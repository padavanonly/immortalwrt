local m = Map("eqos", translate("Network speed control service.(Compatiable with Mediatek HNAT)"))

local s = m:section(TypedSection, "eqos")
s.anonymous = true

local e = s:option(Flag, "enabled", translate("Enable"))
e.rmempty = false


local dl = s:option(Value, "download", translate("Download speed (Mbit/s)"))
dl.description = translate("Total bandwidth")
dl.datatype = "and(uinteger,min(1))"

local ul = s:option(Value, "upload", translate("Upload speed (Mbit/s)"))
ul.description = translate("Total bandwidth")
ul.datatype = "and(uinteger,min(1))"

s = m:section(TypedSection, "device", translate("Speed limit based on IP address(using unique comment which is less than 8 will enable hardware QOS)"))
s.template = "cbi/tblsection"
s.anonymous = true
s.addremove = true
s.sortable  = true

local ip = s:option(Value, "ip", translate("IPv4"))

luci.ip.neighbors({family = 4, dev = "br-lan"}, function(n)
	if n.mac and n.dest then
		ip:value(n.dest:string(), "%s (%s)" %{ n.dest:string(), n.mac })
	end
end)

local mac = s:option(Value, "mac", translate("IPV6"))

luci.ip.neighbors({family = 4, dev = "br-lan"}, function(n)
	if n.mac and n.dest then
		mac:value(n.mac, "%s (%s)" %{ n.dest:string(), n.mac })
	end
end)

dl = s:option(Value, "download", translate("Download speed (kbit/s)"))
dl.datatype = "and(uinteger,min(0))"

ul = s:option(Value, "upload", translate("Upload speed (kbit/s)"))
ul.datatype = "and(uinteger,min(0))"

comment = s:option(Value, "comment", translate("Comment"))
comment.datatype = 'and(uinteger,min(1))';
		comment.rmempty = false;

return m
