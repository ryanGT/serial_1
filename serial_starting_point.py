case = 2# USB, not GPIO serial
if case == 1:
    portname = '/dev/ttyAMA0'
elif case == 2:
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

# USB serial causes Arduino to reboot and print welcome message
## if case == 2:
##     debug_line = Read_Line(ser)
##     line_str = ''.join(debug_line)


def send_and_listen(send_me):
    ser.write(send_me)
    response_list = Read_Line(ser)
    response = ''.join(response_list)
    return response

resp1 = send_and_listen(chr(1))
resp48 = send_and_listen(chr(48))
resp49 = send_and_listen(chr(49))

ser.close()
