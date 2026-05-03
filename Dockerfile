FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++ && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN g++ -std=c++17 -o server backend/main.cpp -I"include" -lpthread

EXPOSE 8080

ENV PORT=8080

CMD ["./server"]