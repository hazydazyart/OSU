# Megan Conley
# conleyme@onid.oregonstate.edu
# CS344-400
# Homework 6

#!user/bin/env python

import socket
import os
import sys
import getopt
import signal
import re

HOST = '128.193.37.0'
PORT = 9998
BUFFSIZE = 4096

sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sockfd.connect((HOST,PORT))

def sig_handler(signum, frame):
	sys.exit()

def send_handshake(sock):
	sock.send("<request= 'handshake' sender= 'report'></request");

def parsexml(packet):
        string = re.compile("[\W\.]+").sub(" ", packet)
        arr = string.split( )
        return arr

signal.signal(signal.SIGHUP, sig_handler)
signal.signal(signal.SIGINT, sig_handler)
signal.signal(signal.SIGQUIT, sig_handler)

# python getopt reference: http://pymotw.com/2/getopt/
options, remainder = getopt.getopt(sys.argv[1:], 'k')
k_set = 0
for opt, arg in options:
	if opt in ('-k'):
		k_set = 1

packet = sockfd.recv(BUFFSIZE)
print "Received handshake from manage."
print packet
send_handshake(sockfd)
print "Sent handshake to manage. Connected to perfect numbers server."

#Request data
print "Sending report request to server."
packet = sockfd.recv(BUFFSIZE)
print "Received data report from manage."
response = parsexml(packet)
print response
#find how many processes there are
num_procs = int(response[5])

#find offset of perfect numbers
mod_idxs = 7 + (2 * num_procs)
num_perfs = response[mod_idxs]

client_rep = "There are "
client_rep += str(num_procs)
client_rep += " clients connected."
print client_rep
print "Client performance statuses: "

idx = 5
for i in range(0, num_procs):
	mod_rep = "Mods per sec: "
	idx += 2 
	mod_rep += response[idx]
	print mod_rep

perf_rep = num_perfs
perf_rep = " perfect numbers found so far."

print "Perfect numbers found:"

idx = mod_idxs
for i in range(0, int(num_perfs)):
	idx += 2
	print response[idx]

if (k_set == 1):
	print "Sending termination request to processes."
	sockfd.send("<request= 'terminate' sender= 'report'>")

sockfd.close()
