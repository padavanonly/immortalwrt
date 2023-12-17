#!/bin/sh /etc/rc.common

start() {


	
   	echo 32768 > /proc/sys/net/netfilter/nf_conntrack_buckets
	echo 16384 > /proc/sys/net/netfilter/nf_conntrack_expect_max
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mt7615/mt7615.1.5G.dat)
    	ssid=$(grep -e "ApCliSsid=" /etc/wireless/mt7615/mt7615.1.5G.dat)
    	iwpriv apcli0 set "$ssid"
    	iwpriv ra0 set "$kick"
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mt7615/mt7615.1.2G.dat)
    	ssid=$(grep -e "ApCliSsid=" /etc/wireless/mt7615/mt7615.1.2G.dat)
    	iwpriv rax0 set "$kick"
    	iwpriv apclix0 set "$ssid"
    	iwpriv apcli0 set ApCliAutoConnect=3
	iwpriv apclix0 set ApCliAutoConnect=3
	iwpriv apcli0 set set ApCliEnable=1
	iwpriv apclix0 set ApCliEnable=1
}



