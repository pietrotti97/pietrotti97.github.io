#!/bin/sh
set uci.button.button.@wps.handler 'wps_button_pressed.sh'
sed -i 's#root:/bin/false#root:/bin/ash#' /etc/passwd
uci set dropbear.lan.RootPasswordAuth='on'
uci set dropbear.lan.RootLogin='1'
echo -e "root\nroot" | passwd
cp /etc/config/web /etc/config/web_bck
uci set web.usr_admin.role='engineer'
uci add_list web.cwmpconf.roles='admin'
uci add_list web.relaymodal.roles='admin'
uci add_list web.relaymodal.roles='engineer'
uci del_list web.relaymodal.roles='dummy'
uci add_list web.isp.roles='admin'
uci add_list web.xdsllowmodal.roles='admin'
uci add_list web.natalghelper.roles='admin'
uci add_list web.systemmodal.roles='admin'
uci add_list web.portmirrormodal.roles='admin'
uci add_list web.portmirrormodal.roles='engineer'
uci del_list web.portmirrormodal.roles='dummy'
uci add_list web.printersharing.roles='admin'
uci set system.@system[0].timezone='CET-1CEST,M3.5.0,M10.5.0/3'
uci set system.@system[0].zonename='Europe/Rome'
uci add_list system.ntp.server='0.it.pool.ntp.org'
uci add_list system.ntp.server='1.it.pool.ntp.org'
uci del_list system.ntp.server='0.openwrt.pool.ntp.org'
uci del_list system.ntp.server='1.openwrt.pool.ntp.org'
uci commit
/etc/init.d/dropbear restart
/etc/init.d/nginx restart
