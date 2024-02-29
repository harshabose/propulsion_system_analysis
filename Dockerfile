FROM ubuntu:latest
LABEL authors="harshabose"

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    python3-dev \
    python3-pip \
    git

RUN pip3 install numpy scipy matplotlib pybind11 aerosandbox

WORKDIR /app

RUN git clone https://github.com/stevengj/nlopt.git && \
    cd nlopt && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install && \
    cd ../.. && \
    rm -rf nlopt

RUN ldconfig

COPY . .

RUN rm -r /app/cmake-build-debug

RUN mkdir -p /app/cmake-build-debug

RUN cmake -DCMAKE_BUILD_TYPE=Release -B /app/cmake-build-debug -S /app

RUN cmake --build /app/cmake-build-debug --target propulsion_system -j 6

WORKDIR /app/cmake-build-debug

CMD ["./propulsion_system"]

#ENTRYPOINT ["top", "-b"]