import socket, struct
import serial, time


arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=115200, timeout=.1) 


localIP = "127.0.0.1"
localPort = 4445
bufferSize = 256

UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
UDPServerSocket.bind((localIP, localPort))
print("UDP server up and listening")

#Car variables
carData = {}
maxrpm = 74
maxspeed = 220

def decodeFlag(flag):
	flagBin = str(bin(flag))
	flags = {"showTurbo":newBool(flagBin[2]),"showKM":not newBool(flagBin[1]),"showBAR":not newBool(flagBin[0])}
	return flags

def newBool(string):
	if(string == "0"):
		return False
	if(string == "1"):
		return True
	

def decodeLights(lightsAvailable,lightsActive):
	lightsAvBin = str(bin(lightsAvailable))[2:][::-1]
	lightsActBin = str(bin(lightsActive))[2:][::-1]
	lights = {}
	totalLights = ["shift_light","full_beam","handbrake","lowbeam","tc","left_turn","right_turn","both_turns","oil_warn","battery_warn","abs","spare_light","lowbeam", "checkengine","fog"]
	for i in range(0,15):
		try:
			lights[totalLights[i]] = newBool(lightsActBin[i])
		except Exception:
			lights[totalLights[i]] = False	
	return lights

def readData():
	global carData
	data = UDPServerSocket.recvfrom(bufferSize)
	#print(data)
	unpackedData = struct.unpack("I4sHBBfffffffIIfff16s16sxxxx",data[0])
	carData = {"time":unpackedData[0],
			"carName":unpackedData[1].decode("utf-8"),
			"flags": decodeFlag(unpackedData[2]),
			"gear": unpackedData[3],
			"PLID": unpackedData[4],
			"speed": unpackedData[5],
			"rpm": unpackedData[6],
			"turboPressure":unpackedData[7],
			"engTemp":unpackedData[8],
			"fuel":unpackedData[9],
			"oilPressure":unpackedData[10],
			"oilTemp":unpackedData[11],
			"lights":decodeLights(unpackedData[12],unpackedData[13]),
			"throttle": unpackedData[14],
			"brake": unpackedData[15],
			"clutch": unpackedData[16],
			"misc1": unpackedData[17],
			"misc2": unpackedData[18]
			}


while(True):
	readData()
	#print(carData["lights"])
	
	rpm = int(carData["rpm"]/100)
	rpm = min(max(1, rpm), maxrpm)
	rpm = "rpm "+str(rpm)+"\n"
	spd = int(carData["speed"]*3.6)
	spd = min(max(1, spd), maxspeed)
	spd = "spd "+str(spd)+"\n"
	arduino.write(bytes(str(rpm), 'utf-8'))
	arduino.write(bytes(str(spd), 'utf-8'))
	leftind = "left "+str(carData["lights"]["left_turn"])+"\n"
	rightind = "right "+str(carData["lights"]["right_turn"])+"\n"
	abslight = "abs "+str(carData["lights"]["abs"])+"\n"
	arduino.write(bytes(str(leftind), 'utf-8'))
	arduino.write(bytes(str(rightind), 'utf-8'))
	arduino.write(bytes(str(abslight), 'utf-8'))
	time.sleep(0.01)

	

