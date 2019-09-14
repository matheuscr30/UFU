import tensorflow as tf
import numpy as np
import os.path

from keras.layers import Conv2D, MaxPooling2D, Dense, Flatten
from keras.models import Sequential, load_model
from keras.utils import to_categorical
from os import listdir
from PIL import Image

default_image_size = tuple((28,28))

index_by_directory = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    '+': 10,
    '-': 11
}

def get_index_by_directory(directory):
    return index_by_directory[directory]

def get_image_matrix(image_dir):
    image_grayscale = Image.open(image_dir).convert('L')
    image_grayscale = image_grayscale.resize(default_image_size, Image.ANTIALIAS)
    image_np = np.asarray(image_grayscale)
    return image_np

def get_train_test_images_from_directory(dataset_dir):
    x_train, x_test, y_train, y_test = [], [], [], []
    directory_list = listdir(dataset_dir)

    # Remove empty directories
    for directory in directory_list:
        if (len(f"{dataset_dir}/{directory}")) < 1 :
            directory_list.remove(directory)

    for directory in directory_list:
        print(f'Converting Images of directory {directory}')
        image_dir = listdir(f"{dataset_dir}/{directory}")

        # Divide 90% for Train and 10% for Test
        split_point = int(0.9*len(image_dir))
        train_images, test_images = image_dir[:split_point], image_dir[split_point:]

        for image in train_images:
            x_train.append(get_image_matrix(f"{dataset_dir}/{directory}/{image}"))
            y_train.append(get_index_by_directory(directory))
        for image in test_images:
            x_test.append(get_image_matrix(f"{dataset_dir}/{directory}/{image}"))
            y_test.append(get_index_by_directory(directory))

    x_train = np.array(x_train)
    x_test = np.array(x_test)

    x_train = (x_train / 255) - 0.5
    x_test = (x_test / 255) - 0.5

    x_train = np.reshape(x_train, (-1, 28, 28, 1))
    x_test = np.reshape(x_test, (-1, 28, 28, 1))

    return x_train, x_test, np.array(y_train), np.array(y_test)

def create_model():
    num_filters = 8
    filter_size = 3
    pool_size = 2

    # Create model
    print("Creating Model...")
    model = Sequential()
    model.add(Conv2D(num_filters, filter_size, input_shape=(28, 28, 1)))
    model.add(MaxPooling2D(pool_size=pool_size))
    model.add(Flatten())
    model.add(Dense(12, activation='softmax'))

    # Compile the model
    print("Compiling Model...")
    model.compile(
      'adam',
      loss='categorical_crossentropy',
      metrics=['accuracy'],
    )

    # Save model
    print("Saving Model...")
    model.save('model/cnn_model.h5')
    return model

def load_model():
    print('Loading Model...')
    model = tf.keras.models.load_model('model/cnn_model.h5')
    model.load_weights('model/cnn_weights.h5')
    return model

def train_model(model):
    train_dataset_dir = "./datasets/"
    x_train, x_test, y_train, y_test = get_train_test_images_from_directory(train_dataset_dir)

    # Train the model.
    print('Training model...')
    model.fit(
      x_train,
      to_categorical(y_train, num_classes=12),
      epochs=3,
      validation_data=(x_test, to_categorical(y_test, num_classes=12))
    )

    # Save weights
    model.save_weights('model/cnn_weights.h5')

if __name__ == '__main__':
    if os.path.exists('model/cnn_model.h5') and os.path.exists('model/cnn_weights.h5'):
        model = load_model()
    else:
        model = create_model()
        train_model(model)

    train_dataset_dir = "./datasets/"
    x_train, x_test, y_train, y_test = get_train_test_images_from_directory(train_dataset_dir)
    # Predict on the first 5 test images.
    x_test = x_test[:5]

    predictions = model.predict(x_test)

    # Print our model's predictions.
    print(np.argmax(predictions, axis=1)) # [7, 2, 1, 0, 4]
    print(y_test[:5])
