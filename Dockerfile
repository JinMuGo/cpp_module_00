FROM ubuntu:latest

RUN apt-get update && apt-get install -y g++ && apt-get install -y make

WORKDIR /app
COPY . /app
RUN make
