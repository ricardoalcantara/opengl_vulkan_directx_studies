# Vulkan Tutorial

https://vulkan-tutorial.com

# Setup

SDK
https://vulkan.lunarg.com/sdk/home

## Linux

download SDK

https://sdk.lunarg.com/sdk/download/1.1.114.0/linux/vulkansdk-linux-x86_64-1.1.114.0.tar.gz?u=


extract somewhere

$ ~/Vulkan


setup the environment variables

if [ -f ~/Vulkan/1.1.114.0/setup-env.sh ]; then
    . ~/Vulkan/1.1.114.0/setup-env.sh
fi

generate Makefiles

$ vendor/linux/premake5 gmake2

compile

$ make

run

cd Drawing_a_triangle
bin/Debug-linux-x86_64/Drawing_a_triangle/Drawing_a_triangle

## Windows