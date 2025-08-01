About the OPNsense plugins
==========================

The plugins collection offers users and developers a way to quickly
build additions for OPNsense that can be optionally installed.  As
soon as they are upstreamed they will become available to everyone
through the firmware GUI pages.

Plugins can do the following:

* Modify the menu, access control lists and look and feel (themes)
* Add additional server software and their respective GUI pages
* Create new authentication methods to be used within other subsystems
* Provide other types of devices and interfaces to the firewall
* Pull in additional packages that will update automatically
* Enhance the backend services with additional work tasks
* Allow custom start, stop and early scripts
* Persistent /boot/loader.conf modifications
* Additional themes for the web GUI

Now we need your help to enrich the plugins.  Feel free to contact us
at project AT opnsense DOT org or open GitHub issue to get in touch.


Stay safe,
Your OPNsense team

A list of currently available plugins
=====================================

```
benchmarks/iperf -- Connection speed tester
databases/redis -- Redis DB
devel/debug -- Debugging Tools
devel/grid_example -- A sample framework application
devel/helloworld -- A sample framework application
dns/bind -- BIND domain name service
dns/ddclient -- Dynamic DNS client
dns/dnscrypt-proxy -- Flexible DNS proxy supporting DNSCrypt and DoH
dns/rfc2136 -- RFC-2136 Support
emulators/qemu-guest-agent -- QEMU Guest Agent for OPNsense
ftp/tftp -- TFTP server
mail/postfix -- SMTP mail relay
mail/rspamd -- Protect your network from spam
misc/theme-advanced -- OPNsense theme based on AdvancedTomato GUI
misc/theme-cicada -- The cicada theme - dark grey onyx
misc/theme-rebellion -- A suitably dark theme
misc/theme-tukan -- The tukan theme - blue/white
misc/theme-vicuna -- The vicuna theme - blue sapphire
net/chrony -- Chrony time synchronisation
net/freeradius -- RADIUS Authentication, Authorization and Accounting Server
net/frr -- The FRRouting Protocol Suite
net/ftp-proxy -- Control ftp-proxy processes
net/google-cloud-sdk -- Google Cloud SDK
net/haproxy -- Reliable, high performance TCP/HTTP load balancer
net/igmp-proxy -- IGMP-Proxy Service
net/mdns-repeater -- Proxy multicast DNS between networks
net/ndproxy -- Neighbor Discovery Proxy
net/ntopng -- Traffic Analysis and Flow Collection
net/radsecproxy -- RADIUS proxy provides both RADIUS UDP and TCP/TLS (RadSec) transport
net/realtek-re -- Realtek re(4) vendor driver
net/relayd -- Relayd Load Balancer
net/shadowsocks -- Secure socks5 proxy
net/siproxd -- Siproxd is a proxy daemon for the SIP protocol
net/sslh -- sslh configuration front-end
net/tayga -- Tayga NAT64
net/turnserver -- The coturn STUN/TURN Server
net/udpbroadcastrelay -- Control udpbroadcastrelay processes
net/upnp -- Universal Plug and Play (UPnP IGD & PCP/NAT-PMP) Service
net/vnstat -- Network traffic monitor
net/wol -- Wake on LAN Service
net/zerotier -- Virtual Networks That Just Work
net-mgmt/collectd -- Collect system and application performance metrics periodically
net-mgmt/lldpd -- LLDP allows you to know exactly on which port is a server
net-mgmt/net-snmp -- Net-SNMP is a daemon for the SNMP protocol
net-mgmt/netdata -- Real-time performance monitoring
net-mgmt/nrpe -- Execute nagios plugins
net-mgmt/telegraf -- Agent for collecting metrics and data
net-mgmt/zabbix-agent -- Zabbix monitoring agent
net-mgmt/zabbix-proxy -- Zabbix monitoring proxy
security/acme-client -- ACME Client
security/clamav -- Antivirus engine for detecting malicious threats
security/crowdsec -- Lightweight and collaborative security engine
security/etpro-telemetry -- ET Pro Telemetry Edition
security/intrusion-detection-content-et-open -- IDS Proofpoint full ET open ruleset complementary subset for ET Pro Telemetry edition
security/intrusion-detection-content-et-pro -- IDS Proofpoint ET Pro ruleset (needs a valid subscription)
security/intrusion-detection-content-pt-open -- IDS Positive Technologies ESC ruleset
security/intrusion-detection-content-snort-vrt -- IDS Snort VRT ruleset (needs registration or subscription)
security/maltrail -- Malicious traffic detection system
security/netbird -- Peer-to-peer VPN that seamlessly connects your devices (development only)
security/openconnect -- OpenConnect Client
security/openvpn-legacy -- OpenVPN legacy support
security/softether -- Cross-platform Multi-protocol VPN Program (development only)
security/strongswan-legacy -- IPsec legacy support
security/stunnel -- Stunnel TLS proxy
security/tailscale -- VPN mesh securely connecting clients using WireGuard
security/tinc -- Tinc VPN
security/tor -- The Onion Router
security/wazuh-agent -- Agent for the open source security platform Wazuh
sysutils/apcupsd -- APCUPSD - APC UPS daemon
sysutils/apuled -- PC Engine APU LED control (development only)
sysutils/beats -- Send logs, network, metrics and heartbeat to Elasticsearch
sysutils/cpu-microcode -- CPU microcode updates
sysutils/dec-hw -- Deciso hardware specific information
sysutils/dmidecode -- Display hardware information on the dashboard
sysutils/gdrive-backup -- Backup configurations using Google Drive
sysutils/git-backup -- Track config changes using git
sysutils/hw-probe -- Collect hardware diagnostics
sysutils/lcdproc-sdeclcd -- LCDProc for SDEC LCD devices
sysutils/mail-backup -- Send configuration file backup by e-mail
sysutils/munin-node -- Munin monitoring agent
sysutils/nextcloud-backup -- Track config changes using NextCloud
sysutils/node_exporter -- Prometheus exporter for machine metrics
sysutils/nut -- Network UPS Tools
sysutils/puppet-agent -- Manage Puppet Agent
sysutils/sftp-backup -- Backup configurations using SFTP
sysutils/smart -- SMART tools
sysutils/virtualbox -- VirtualBox guest additions
sysutils/vmware -- VMware tools
sysutils/xen -- Xen guest utilities
vendor/sunnyvalley -- Vendor Repository for Zenarmor (Enterprise Security Modules - NGFW, SSE, SASE, f.k.a Sensei)
www/OPNProxy -- OPNsense proxy additions
www/c-icap -- c-icap connects the web proxy with a virus scanner
www/cache -- Webserver cache
www/caddy -- Modern Reverse Proxy with Automatic HTTPS, Dynamic DNS and Layer4 Routing
www/nginx -- Nginx HTTP server and reverse proxy
www/squid -- Squid is a caching proxy for the web
www/web-proxy-sso -- Kerberos authentication module
```

A brief description of how to use the plugins repository
========================================================

The workflow of the plugins repository is quite similar to the
core repository, although the plugins have one source directory
per plugin, while the core can be thought of a lone plugin.

Commits for individual plugins should therefore be split into
individual chunks for each src/ directory so that they can be
reviewed separately and also be applied remotely.

When an OPNsense release is built, the plugins are automatically
added to the final package repository.

The most useful Makefile targets and their purpose is described
below.

The make targets for the root directory:

* clean:	remove all changes and unknown files
* lint:		run syntax checks
* list:		print a list of all plugin directories with comments
* style:	run style checks
* sweep:	apply style fixes

The make targets for any plugin directory:

* clean:	remove all changes and unknown files
* collect:	gather updates from target directory
* install:	install to target directory
* lint:		run syntax checks
* package:	creates a package
* upgrade:	upgrades existing package
* remove:	remove known files from target directory
* style:	run style checks
* sweep:	apply style fixes
