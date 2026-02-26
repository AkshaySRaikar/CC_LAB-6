FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /app

COPY app.cpp .

RUN apt-get update && \
    apt-get install -y g++ && \
    rm -rf /var/lib/apt/lists/*

RUN g++ app.cpp -o app

EXPOSE 8080

CMD ["./app"]
