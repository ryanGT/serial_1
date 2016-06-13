case = 2# USB, not GPIO serial
if case == 1:
    portname = '/dev/ttyAMA0'
elif case == 2:
    #USB
    portname = '/dev/ttyACM0'
    
import serial
ser = serial.Serial(portname, 115200, timeout=1)
ser.open()

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
if case == 2:
    debug_line = serial_utils.Read_Line(ser)
    line_str = ''.join(debug_line)

ser.write(chr("1"))

response = serial_utils.Read_Line(ser)

ser.close()
