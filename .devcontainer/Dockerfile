# FROM fedora:40
FROM almalinux:9

RUN dnf -y update

RUN dnf -y install wget python3-pip git cmake gcc g++ vim zlib-devel libusbx-devel which libtool clang-tools-extra openssl-devel libffi-devel libxcrypt-compat patch socat nmap-ncat

# COPY resolv.conf /etc/resolv.conf

# open cmsis pack for pyocd
# https://keilpack.azureedge.net/pack/Keil.STM32F4xx_DFP.3.1.1.pack

# RUN git clone https://github.com/openocd-org/openocd.git && \
#     cd openocd && ./bootstrap && \
#     ./configure --enable-ftdi --enable-cmsis-dap --enable-stlink && \
#     make -j$(nproc) && make install


# COPY arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi.tar.xz /arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi.tar.xz

# Toolchain
RUN  \
    wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu/14.3.rel1/binrel/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi.tar.xz &&\
    tar xvf arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi.tar.xz -C /opt/ && \
    rm -f arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi.tar.xz &&\
    sh -c 'dnf -y install almalinux-release-devel' &&\
    dnf -y  install ncurses-compat-libs

# SVD file
COPY STM32F411.svd /STM32F411.svd

# Python 3.8 for gdb in toolchain
RUN \
    wget https://www.python.org/ftp/python/3.14.2/Python-3.14.2.tgz &&\
    tar -xvf Python-3.14.2.tgz &&\
    cd Python-3.14.2 &&\
    ./configure && make -j8 install &&\
    cd .. && rm Python-3.14.2.tgz && rm -rf Python-3.14.2

# Gitman
RUN python3 -m pip install gitman

# PyOCD
RUN python3 -m pip install pyocd

# elf-size-analyze
RUN python3 -m pip install elf-size-analyze

# Create the user
RUN dnf -y  install sudo

# install boost
# RUN dnf -y  install boost-devel

ARG USERNAME=user
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

RUN dnf -y clean all

RUN ln -s /opt/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi /opt/arm-none-eabi
RUN echo "export PATH=\"/opt/arm-none-eabi/bin:$PATH\"" > /etc/profile.d/arm-none-eabi.sh

# build picolibc
# RUN pip install meson
# RUN dnf -y  install 'dnf-command(config-manager)' && dnf -y config-manager --set-enabled crb && dnf -y install ninja-build
# RUN git clone https://github.com/picolibc/picolibc --depth 1 && cd picolibc && mkdir build && cd build && source /etc/profile.d/arm-none-eabi.sh && ../scripts/do-arm-configure && ninja && ninja install

COPY bash-history /home/user/.bash_history
RUN chown user:user /home/user/.bash_history

USER $USERNAME
ENTRYPOINT ["/usr/bin/sleep", "infinity"]
