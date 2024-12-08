FROM gcc:latest

RUN apt-get update && apt-get install -y \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN g++ -o taller src/main.cpp src/model/tablero/Tablero.cpp src/model/minimax/Minimax.cpp

RUN chmod +x ./taller

CMD ["./taller"]
