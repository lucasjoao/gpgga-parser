# gpgga-parser

Parser que a partir de uma mensagem GPGGA NMEA que contêm latitude, longitude, altitude e horário retorna as coordenadas no sistema ECEF e o seu timestamp.

# Execução

Há três possibilidades:

- `make` irá pegar uma mensagem NMEA GPGGA aleatória para realizar o parse e apresentar o resultado
- `make arg=show` irá retornar uma mensagem NMEA GPGGA aleatória
- `make arg=MENSAGEM` irá pegar a *MENSAGEM* passada como argumento para realizar o parse e apresentar o resultado
