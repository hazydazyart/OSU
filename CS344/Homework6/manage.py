# Megan Conley
# conleyme@onid.oregonstate.edu
# CS344-400
# Homework 6

#!user/bin/env python

import signal
import socket
import os
import time
import select
import sys
import re
from math import sqrt

perfects = []
comp_procs = dict()
command = []
all_cnxs = []

# signal handler
def sighandler(signum, frame):
	terminate()
	sys.exit()

signal.signal(signal.SIGHUP, sighandler)
signal.signal(signal.SIGINT, sighandler)
signal.signal(signal.SIGQUIT, sighandler)

HOST = '128.193.37.0'
PORT = 9998
BUFFSIZE = 4096

def parsexml(packet):
	string = re.compile("[\W_]+").sub(" ", packet)
	arr = string.split( )
	return arr

def send_handshake(sock):
	sock.send("<request= 'handshake' sender= 'manage' />")

def get_handshake(sock):
	response = sock.recv(BUFFSIZE)
	parsed = parsexml(response)
	host,port = sock.getpeername()
	if(parsed[1] == 'handshake'):
		if(parsed[3] == 'cman'):
			print "New compute process manager joined."
			command.append(sock)
		if(parsed[3] == 'compute'):
			print "New compute process joined."
		if(parsed[3] == 'report'):
			print "New report client joined."	

def find_next_max(prev, mods):
	ceiling = .5 * (mods*15);
	temp = 0;
	new_max = prev + 1;
	while(temp < ceiling):
		temp += sqrt(new_max)
		new_max += 1;
	return new_max

def terminate():
	print "Termination request received."
	if(command):
		for i in command: 
			i.send("<request= 'terminate' sender= 'manage'></request>")
	sys.exit()

if __name__ == "__main__":
      
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("128.193.37.0", PORT))
    server_socket.listen(10)
 
    # Add server socket to the list of readable connections
    all_cnxs.append(server_socket)
 
    print "Perfect numbers program started on port " + str(PORT)
 
    while 1:
        # Get the list sockets which are ready to be read through select
        read_sockets,write_sockets,error_sockets = select.select(all_cnxs,[],[])
 
        for sock in read_sockets:
             
            #New connection
            if sock == server_socket:
                sockfd, addr = server_socket.accept()
                all_cnxs.append(sockfd)
		send_handshake(sockfd)
		get_handshake(sockfd)
                 
            #Some incoming message from a client
            else:
            	data = sock.recv(BUFFSIZE)
		# print data
            	if(data == ''):
			print "Client left"
			sock.close()
			all_cnxs.remove(sock)
		else:
		#	for packet in data:
		#		if(packet != ''):
		#			print packet
					pack = parsexml(data)
					if(pack[3] == 'report'):
						if(pack[1] == 'terminate'):
							print "Termination request received. Ending program."
							terminate()
							sock_server.close()
							sys.exit()
						elif(pack[1] == 'report'):
							print "Report requested performance report."
							response = "<request= 'data' sender= 'manage'>"
							if comp_procs:
								print "Sending performance report."
								num = len(comp_procs)
								response += "<numclients= '"
								response += str(num)
								response += " />"
								for host, mods in comp_procs.iteritems():
									response += "<mods= '"
									response += str(mods)
									response += "' />"
							if perfects:
								num_p = len(perfects)
								response += "<num_perf= "
								response += str(num_p)
								response += " />"
								for p in perfects:
									response += "<perfect= "
									response += p
									response += " />"
							response += "</request>"
							sock.send(response)
					elif(pack[3] == 'compute'):
						if(pack[1] == 'perfect'):
							print "New perfect sent by compute process. Appending to list."
							newperf = pack[5];
							if newperf not in perfects:
								perfects.append(newperf)
						elif(pack[1] == 'getrange'):
							#get performance and prev max from client
							mods = int(pack[5])
							prevmax = int(pack[7])
							host,port = sock.getpeername()
							comp_procs[host] = mods
							if(prevmax != 4294967295):
								#have not hit max yet
								print "New range requested from client. Client's previous max was: ", prevmax, "Performance: ", mods, "mods per sec."
								response = "<request= 'newrange' sender= 'manage' "
								#if this is first request
								if(prevmax == 0):
									response += "min= 1 "
								else:
									response += "min= "
									prevmax += 1
									response += str(prevmax)
									response += " "
								response += "max= "
								next_max = find_next_max(prevmax, mods)
								if(next_max > 4294967295):
									next_max = 4294967295
								response += str(next_max)
								response += " /></request>"
								sock.send(response)
							else: # ceiling hit, end the process
								terminate()
			
         
server_socket.close()
sys.exit(0)
