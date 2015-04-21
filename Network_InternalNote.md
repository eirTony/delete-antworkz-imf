# Introduction #

This TechNote will document the internal
Research and Development intranet (AKA RadNet).

# Physical Hosts #

## Emmetts ##

...

## Firestone ##

...

# Virtual Hosts #

Virtualization will be a major part of the use of RadNet.
We currently use the Oracle VM  system: VirtualBox.

## Oracle VirtualBox Setup ##

  * For Linux/BSD physical hosts you may be able to install a VirtualBox-4.3.20 package
  * If necessary, download from https://www.virtualbox.org/wiki/Downloads
  * Install and start the Manager
  * Set its default path to [Windows](Windows.md) V:\ or [Linux/BSD] /home/vboxlive

## Creating VBox Clients ##

  * From **VirtualBox Manager**, create a new Virtual Machine by one of the following:
    * Select _New_ action
    * _Clone_ or _Import_ an appropriate -Base machine

  * Naming the virtual machine: An OS identifier and use connected by a hyphen.
    * Windows-based OS
      * W7x86 = Windows 7 - 32 bit
      * W7x64 = Windows 7 - 64 bit
      * W8x64 = Windows 8 - 64 bit
    * Linux-based OS [add +KDE if X GUI is included)
      * PCL64 = PCLinuxOS (v14.08 for now) - 64 bit
      * Fed64 = Fedora (v20 for now) - 64 bit
      * Orac64 = Oracle Linux (v7 for now) - 64 bit
      * Cent64 = Centos (v7 for now) - 64 bit
    * BSD-based OS
      * Free64 = FreeBSD (version TBD) - 64bit
      * others TBD
    * Use Identifiers
      * Bare
      * Base
      * App
      * Qt[4|5]Dev
      * [Daily|Weekly]

  * Feed it the ISO image for that OS

  * Start the new virtual machine
    * Install VBox Guest Additions
    * Use the appropriate update facility
      * Repeat until it wont update any more, restart as required
      * [Windows](Windows.md) Also Windows Defender definitions
    * Add users

  * Install software based upon use (except -Bare)

  * Configure the machine

  * Shutdown the machine

  * Export to OVA file on [Windows](Windows.md) O: drive or [Linux](Linux.md) /home/vbox/live path

  * Copy the OVA to archive fist drive [Windows](Windows.md) Q: or [Linux](Linux.md) /mnt/OVArchive

  * Rince and repeat for all of the OS-Use combinations required

  * Import as needed on Firestone and Lucky