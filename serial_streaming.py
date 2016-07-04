#USB
portname = '/dev/ttyACM0'
    
import serial
ser = serial.Serial(portname, 115200, timeout=1)
#ser.open()

ser.flushInput()
ser.flushOutput()

def Read_Line(ser):
    out = []
    i = 0
    while i < 1e5:
        data1 = ser.read(1)
        if data1 in ['\n','\r']:
            break
        out.append(data1)
        i += 1
    return out


def send_and_listen(send_me):
    ser.write(send_me)
    response_list = Read_Line(ser)
    response = ''.join(response_list)
    return response

msg = send_and_listen("0")
print(msg)


nvect = arange(255)
resp_list = []

case = 2

if case == 2:
    inByte = chr(2)
elif case == 3:
    inByte = chr(3)
    

for n in nvect:
    # send inByte
    ser.write(inByte)
    # send dataByte
    ser.write(chr(n))
    # read one byte
    resp = ser.read(1)
    resp_list.append(resp)


ser.close()
