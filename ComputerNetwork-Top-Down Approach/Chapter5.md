### 6. ICMP: The Internet Control Message Prottocol 
a:
* Used by hosts & routers to communicate network-level information
  * Error reporting: unreachable host, network, port, protocol
  * Echo request/reply (used by ping)
* Network-layer "above" IP: 
  * ICMP msgs carried in IP datagrams
* ICMP message:
  * Type, code plus first 8 bytes of IP datagram causing error
* Source sends series of UDP segments to destination
  * first set has TTL = 1
  * second set has TTL = 2, etc.
  * unlikely port number
* When datagram in nth set arrives to nth router:
  * router discards datagram and sends source ICMP message (type II, code 0)
  * ICMP message include name of router & IP address
* When ICMP message arrives, source records RTTs：
b. Stopping Criteria:
* UDP segment eventually arrives at destination host
* Destination returns ICMP "port unreachable" message (type 3, code 3)
* Source stops
