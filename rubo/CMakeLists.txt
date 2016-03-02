# Set a variable for commands below
set(PROJECT_NAME remote-control-rubo)

# Define your project and language
project(${PROJECT_NAME} C CXX)

set(${PROJECT_NAME}_BOARD atmega328)

# Define the source code
set(${PROJECT_NAME}_SRCS remote-control-rubo-main.cpp input.cpp output.cpp)

# Define the port for uploading code to the Arduino
set(${PROJECT_NAME}_PORT /dev/ttyUSB0)

# Command to generate code arduino firmware (.hex file)
generate_arduino_firmware(${PROJECT_NAME})
