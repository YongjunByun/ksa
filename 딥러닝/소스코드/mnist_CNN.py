from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Model, Sequential
from tensorflow.keras.layers import Dense, Input, Activation
from tensorflow.keras.layers import Flatten, Conv2D, MaxPooling2D, Dropout, BatchNormalization
from tensorflow.keras.utils import to_categorical
from keras import backend as K
import matplotlib.pyplot as plt
import numpy as np

#loss 그래프 그리기
def plot_loss(history):
    plt.plot(history.history['loss'])
    plt.plot(history.history['val_loss'])
    plt.title('Model loss')
    plt.ylabel('Loss')
    plt.xlabel('Epoch')
    plt.legend(['Train', 'val'], loc=0)


def plot_acc(history):
    plt.plot(history.history['accuracy'])
    plt.plot(history.history['val_accuracy'])
    plt.title('Model accuracy')
    plt.ylabel('accuracy')
    plt.xlabel('Epoch')
    plt.legend(['Train', 'accuracy'], loc=0)

# 하이퍼파라미터 설정
np.random.seed(1337)
batch_size = 128
num_classes=10
epochs=12

# 이미지 차원 입력
img_rows, img_cols = 28, 28

nb_filters = 32

# 데이터 로드
(X_train, y_train), (X_test, y_test) = mnist.load_data()

# tensorflow backend 사용시 (Height, Width, channel) 순 입력, Theano backend 사용시 (channel, Height, Width) 순 입력
if K.image_dim_ordering() == 'th':
    X_train = X_train.reshape(X_train.shape[0], 1, img_rows, img_cols)
    X_test = X_test.reshape(X_test.shape[0], 1, img_rows, img_cols)
    input_shape = (1, img_rows, img_cols)
else:
    X_train = X_train.reshape(X_train.shape[0], img_rows, img_cols, 1)
    X_test = X_test.reshape(X_test.shape[0], img_rows, img_cols, 1)
    input_shape = (img_rows, img_cols, 1)

# 데이터 정규화
X_train = X_train.astype('float32')
X_test = X_test.astype('float32')
X_train /= 255
X_test /= 255

print(X_train.shape[0], 'train samples')
print(X_test.shape[0], 'test samples')

# 라벨
y_train = to_categorical(y_train, num_classes)
y_test = to_categorical(y_test, num_classes)

# 네트워크 정의
# function()
input_tensor = Input(shape=input_shape)
x = Conv2D(nb_filters, kernel_size=(3,3), padding='valid', name='Conv1')(input_tensor)
x = Activation('relu', name='relu_1')(x)
x = Conv2D(nb_filters, kernel_size=(3,3), padding='valid', name='Conv2')(x)
x = Activation('relu', name='relu_2')(x)
x = MaxPooling2D(pool_size=(2,2), name='pool_1')(x)
x = Flatten()(x)
x = Dense(units=128, name='hidden_1')(x)
x = Activation('relu', name='relu_3')(x)
x = Dense(units=num_classes, name='hidden_2')(x)
output_tensor = Activation('softmax', name='output_tensor')(x)
model = Model(inputs=input_tensor, outputs=output_tensor)
model.summary()

# 모델 학습
model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

history = model.fit(X_train, y_train, batch_size=batch_size, epochs=epochs, verbose=1, validation_split=0.2)
print('\nTest start')
score = model.evaluate(X_test, y_test, verbose=1)
print('Test loss:', score[0])
print('Test accuracy:', score[1])

