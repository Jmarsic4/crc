#---------------------------------------------------------------------------------------
def byte_mirror(c):

    c = (c & 0xF0) >> 4 | (c & 0x0F) << 4
    c = (c & 0xCC) >> 2 | (c & 0x33) << 2
    c = (c & 0xAA) >> 1 | (c & 0x55) << 1

    return c

#---------------------------------------------------------------------------------------
#20.5.2020
#V12 works nice
#This algoritham is for CRC calculation CRC-CCIT using in the HDLC
#
#Josko Marsic josko.marsic@gmail.com
#---------------------------------------------------------------------------------------
#http://www.zorc.breitbandkatze.de/crc.html
#CRC order           -16
#CRC polynom         -1021
#Initial value       -FFFF
#Final XOR value     -FFFF
#reverse data bytes  -yes
#reverse CRC result..-yes
#Data sequence       -%A0%08%03%02%FF%93
#Results
#E4CA
#---------------------------------------------------------------------------------------

CRC_INIT=0xffff
POLYNOMIAL=0x1021
DATA_VALUE=0xA0

SNRM_request=[ 0x7E, 0xA0, 0x08, 0x03, 0x02, 0xFF, 0x93, 0xCA, 0xE4, 0x7E]

print("sent>>", end=" ")

for x in SNRM_request:
  if x>15:
       print(hex(x), end=" ")
  else:
       a=str(hex(x))
       a = a[:2] + "0" + a[2:]
       print(a, end=" ")

lenn=len(SNRM_request)
print(" ")

crc = CRC_INIT



for i in range(lenn):

    if( (i!=0) and (i!=(lenn-1)) and (i!=(lenn-2)) and (i!=(lenn-3)) ):

        print("i>>",i)

        c=SNRM_request[i]
        c=byte_mirror(c)
        c = c << 8
        
        print(hex(c))

        for j in range(8):
      
            print(hex(c))
            print("CRC",hex(crc))

            if (crc ^ c) & 0x8000:
                crc = (crc << 1) ^ POLYNOMIAL
            else:
                crc = crc << 1

            c = c << 1   
            crc=crc%65536
            c  =c%65536


print("CRC-CALC",hex(crc))

crc=0xFFFF-crc          #crc=~crc

print("CRC- NOT",hex(crc))

crc_HI=crc//256
crc_LO=crc%256

print("CRC-HI",hex(crc_HI))
print("CRC-LO",hex(crc_LO))

crc_HI=byte_mirror(crc_HI)
crc_LO=byte_mirror(crc_LO)

print("CRC-HI-zrc",hex(crc_HI))
print("CRC-LO-zrc",hex(crc_LO))

crc=256*crc_HI+crc_LO
print("CRC-END",hex(crc))




