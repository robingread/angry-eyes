FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive
ENV QT_DEBUG_PLUGINS=1
# ENV QT_QPA_PLATFORM=offscreen
ENV QT_GRAPHICSSYSTEM="native"

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        libqt5x11extras5 \
        libxkbcommon-x11-0 \
        qt5-default && \
    rm -rf /var/lib/apt/lists/*

COPY . /code
WORKDIR /code
RUN qmake -o Makefile *.pro && \
    make

CMD ["angry_eyes"]
