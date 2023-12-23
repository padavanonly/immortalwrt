#!/bin/sh /etc/rc.common

start() {
	sleep 10
   	echo 32768 > /proc/sys/net/netfilter/nf_conntrack_buckets
	echo 16384 > /proc/sys/net/netfilter/nf_conntrack_expect_max
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mt7615/mt7615.1.5G.dat)
    	iwpriv ra0 set "$kick"
    	kick=$(grep -e "KickStaRssiLow=" /etc/wireless/mt7615/mt7615.1.2G.dat)
    	iwpriv rax0 set "$kick"
    	
    	ssid=$(grep -e "ApCliSsid=" /etc/wireless/mt7615/mt7615.1.5G.dat)
    	ApCliEnable=$(grep -e "ApCliEnable=" /etc/wireless/mt7615/mt7615.1.5G.dat)
    	if [ "$ApCliEnable" = "ApCliEnable=1" ] ; then
    	iwpriv apcli0 set "$ssid"
	iwpriv apcli0 set ApCliEnable=0
	iwpriv apcli0 set Channel=0
	iwpriv apcli0 set ApCliAutoConnect=0
	iwpriv apcli0 set ApCliAutoConnect=1
	iwpriv apcli0 set ApCliAutoConnect=3
	iwpriv apcli0 set ApCliEnable=1
	fi
	
	ssid=$(grep -e "ApCliSsid=" /etc/wireless/mt7615/mt7615.1.2G.dat)
	ApCliEnable=$(grep -e "ApCliEnable=" /etc/wireless/mt7615/mt7615.1.2G.dat)
	if [ "$ApCliEnable" = "ApCliEnable=1" ] ; then
    	iwpriv apclix0 set "$ssid"
	iwpriv apclix0 set ApCliEnable=0	
    	iwpriv apclix0 set Channel=0
    	iwpriv apclix0 set ApCliAutoConnect=0
    	iwpriv apclix0 set ApCliAutoConnect=1
	iwpriv apclix0 set ApCliAutoConnect=3
	iwpriv apclix0 set ApCliEnable=1
	fi
}



