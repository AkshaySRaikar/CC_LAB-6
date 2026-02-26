FROM ubuntu:20.04

WORKDIR /app

COPY app.cpp .

RUN apt-get update && \
    apt-get install -y g++ && \
    g++ app.cpp -o app

EXPOSE 8080

CMD ["./app"]
