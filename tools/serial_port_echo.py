import serial

def main(port):
  with serial.Serial(port, 19200, timeout=1) as ser:
    print(f'waiting on {port}')
    while True:
      line = ser.readline()   # read a '\n' terminated line
      print(f'received: {line}')

      if line:
        ser.write(line)
        print(f'transmitted: {line} ')

if __name__ == "__main__":
  port = 'COM2'
  main(port)