FROM ubuntu:22.04

# Install g++ compiler
RUN apt-get update && apt-get install -y g++ && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy everything
COPY . .

# Compile C++ server
RUN g++ -std=c++17 -o server backend/main.cpp -I"include" -lpthread

# Expose port
EXPOSE 8080

# Run server
CMD ["./server"]