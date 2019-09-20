# IEEE-2019

Boberto da IEEE

[Regras](http://www.cbrobotica.org/wp-content/uploads/OPEN2018_2019_en.pdf)

## Pinout do Boberto

### Motor de Passo

| Port      | Pin     |
|:--------: |:-------:|
| Dir       | 52      |
| Step      | 50      |
| Enable    | 13      |

### Ponte H1

| Port      | Pin     |
|:--------: |:-------:|
| Motor 1.1 | 11      |
| Motor 1.2 | 12      |
| Motor 2.1 | 9       |
| Motor 2.2 | 10      |


### Ponte H2

| Port      | Pin     |
|:--------: |:-------:|
| Motor 1.1 | 7       |
| Motor 1.2 | 8       |
| Motor 2.1 | 6       |
| Motor 2.2 | 5       |

### Ponte H3

| Port      | Pin     |
|:--------: |:-------:|
| Motor 1.1 | 45      |
| Motor 1.2 | 4       |
| Motor 2.1 | 46      |
| Motor 2.2 | 44      |

### Encoders

| Port      | Pin     |
|:--------: |:-------:|
| Motor 1   | 3       |
| Motor 2   | 2       |
| Motor 3   | 18      |
| Motor 4   | 19      |

## Utilizando [PlatformIO Cli](http://docs.platformio.org/en/latest/)

* Instalação

```console
user@computer:~$ sudo python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"
```

* Upload de código

```console
user@computer:~/IEEE-2019 $ pio run -t upload --upload-port=/dev/ttyUSB0
```

## Esquemático das coisas

![arduinoMega](./readme_imgs/arduinoMega.png)

![rasp](./readme_imgs/raspberry.jpeg)
