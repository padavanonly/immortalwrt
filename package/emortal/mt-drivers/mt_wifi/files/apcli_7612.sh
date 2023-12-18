#!/bin/sh /etc/rc.common

start() {
	sleep 10
   	echo 32768 > /proc/sys/net/netfilter/nf_conntrack_buckets
	echo 16384 > /proc/sys/net/netfilter/nf_conntrack_expect_max
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mt7615/mt7615.2.dat)
    	iwpriv rai0 set "$kick"
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mt7615/mt7615.1.dat)
    	iwpriv ra0 set "$kick"
    	
    	ssid=$(grep -e "ApCliSsid=" /etc/wireless/mt7615/mt7615.2.dat)
    	iwpriv apclii0 set "$ssid"
	iwpriv apclii0 set ApCliEnable=0
	iwpriv apclii0 set Channel=0
	iwpriv apclii0 set ApCliAutoConnect=0
	iwpriv apclii0 set ApCliAutoConnect=1
	iwpriv apclii0 set ApCliEnable=1
	
	ssid=$(grep -e "ApCliSsid=" /etc/wireless/mt7615/mt7615.1.dat)
    	iwpriv apcli0 set "$ssid"
	iwpriv apcli0 set ApCliEnable=0	
    	iwpriv apcli0 set Channel=0
    	iwpriv apcli0 set ApCliAutoConnect=0
    	iwpriv apcli0 set ApCliAutoConnect=1
	iwpriv apcli0 set ApCliAutoConnect=3
	iwpriv apcli0 set ApCliEnable=1
}



