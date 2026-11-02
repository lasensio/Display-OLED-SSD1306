# Display OLED com sensor DHT11

Projeto PlatformIO para Arduino Uno que alterna no display OLED SSD1306 as
leituras de temperatura e umidade do sensor DHT11 a cada 4 segundos.

## Conexoes

- DHT11: DATA no pino A1, VCC em 5 V e GND em GND.
- OLED SSD1306 I2C: SDA em A4 e SCL em A5; conecte tambem VCC e GND.

## Diagrama do circuito

![Diagrama de ligacao do Arduino Uno, display OLED e sensor DHT11](Diagrama%20-%20Display%20e%20DHT11_bb.jpg)

O arquivo editavel do diagrama pode ser aberto no Fritzing:
[Diagrama - Display e DHT11.fzz](Diagrama%20-%20Display%20e%20DHT11.fzz).

## Compilar

Abra o projeto no PlatformIO e execute:

```sh
pio run -e uno
```

As bibliotecas necessarias estao declaradas em `platformio.ini`.
