#ifndef __UdpReceiveThread_h__
#define __UdpReceiveThread_h__

#include "NfpvrTypes.h"
#include "NfpvrSystem.h"

class UdpReceiveThread
{
public:
	UdpReceiveThread(nfpvr_socket_t socket, int bufferLength, int bufferCount);
	static DWORD WINAPI entry(LPVOID param);
	int get(uint8* data, const int length, sockaddr_in* sender);

private:
	nfpvr_socket_t _socket;
	uint8*         _data;
	int*           _lengths;
	sockaddr_in*   _senders;

	int            _bufferCount;
	int            _bufferLength;

	int            _readIndex;
	int            _writeIndex;

	HANDLE         _available, _occupied;
	HANDLE         _access;
};

#endif
