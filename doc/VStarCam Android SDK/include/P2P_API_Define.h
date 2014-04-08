
#ifndef _P2P_API_DEFINE_H_
#define _P2P_API_DEFINE_H_

typedef void (*AVDataCallback)(long nHandle, int bVideo, char *pData, int len, void *pParam);
typedef void (*MessageCallback)(long nHandle, int type, char *msg, int len, void *pParam);



//Message type
#define MSG_TYPE_P2P_STATUS         0x0
#define MSG_TYPE_P2P_MODE           0x1
#define MSG_TYPE_GET_CAMERA_PARAMS  0x2
#define MSG_TYPE_DECODER_CONTROL    0x3
#define MSG_TYPE_GET_PARAMS         0x4
#define MSG_TYPE_SNAPSHOT           0x5
#define MSG_TYPE_CAMERA_CONTROL     0x6
#define MSG_TYPE_SET_NETWORK        0x7
#define MSG_TYPE_REBOOT_DEVICE      0x8
#define MSG_TYPE_RESTORE_FACTORY    0x9
#define MSG_TYPE_SET_USER           0xa
#define MSG_TYPE_SET_WIFI           0xb
#define MSG_TYPE_SET_DATETIME       0xc
#define MSG_TYPE_GET_STATUS         0xd
#define MSG_TYPE_GET_PTZ_PARAMS     0xe
#define MSG_TYPE_SET_DDNS           0xf
#define MSG_TYPE_SET_MAIL           0x10
#define MSG_TYPE_SET_FTP            0x11
#define MSG_TYPE_SET_ALARM          0x12
#define MSG_TYPE_SET_PTZ            0x13
#define MSG_TYPE_WIFI_SCAN          0x14
#define MSG_TYPE_GET_ALARM_LOG      0x15
#define MSG_TYPE_GET_RECORD         0x16
#define MSG_TYPE_GET_RECORD_FILE    0x17
#define MSG_TYPE_SET_PPPOE          0x18
#define MSG_TYPE_SET_UPNP           0x19
#define MSG_TYPE_DEL_RECORD_FILE    0x1a
#define MSG_TYPE_SET_MEDIA          0x1b
#define MSG_TYPE_SET_RECORD_SCH     0x1c
#define MSG_TYPE_CLEAR_ALARM_LOG    0x1d
#define MSG_TYPE_WIFI_PARAMS        0x1f
#define MSG_TYPE_MAIL_PARAMS        0x20
#define MSG_TYPE_FTP_PARAMS         0x21
#define MSG_TYPE_NETWORK_PARAMS     0x22
#define MSG_TYPE_USER_INFO          0x23
#define MSG_TYPE_DDNS_PARAMS        0x24
#define MSG_TYPE_DATETIME_PARAMS    0x25
#define MSG_TYPE_ALARM_PARAMS       0x26
#define MSG_TYPE_SET_DEVNAME        0x27
#define MSG_TYPE_ALARM_NOTIFY       0x28
#define MSG_TYPE_PLAY_BACK_START    0x29
#define MSG_TYPE_PLAY_BACK_STOP     0x30
#define MSG_TYPE_FORMAT_SDCARD      0x31


//alarm notify
#define ALARM_MOTION    0x1
#define ALARM_IO    0x2
   


//p2p status
#define P2P_STATUS_CONNECT_TIME_OUT         0x0
#define P2P_STATUS_INVALID_ID               0x1
#define P2P_STATUS_CONNECT_SUCCESS          0x2
#define P2P_STATUS_DISCONNECTED             0x3
#define P2P_STATUS_CONNECT_FAIlED           0x4
#define P2P_STATUS_CONNECTING               0x5
#define P2P_STATUS_DEVICE_NOT_ON_LINE       0x6
#define P2P_STATUS_INVALID_USER_PWD         0x7

//p2p mode
#define P2P_MODE_P2P_RELAY                  0x0
#define P2P_MODE_P2P_CONNECTED              0x1

//decoder control command
#define CMD_PTZ_UP                      0
#define CMD_PTZ_UP_STOP                 1
#define CMD_PTZ_DOWN                    2
#define CMD_PTZ_DOWN_STOP               3
#define CMD_PTZ_LEFT                    4
#define CMD_PTZ_LEFT_STOP               5
#define CMD_PTZ_RIGHT                   6
#define CMD_PTZ_RIGHT_STOP             	7

#define CMD_PTZ_CENTER                  25
#define CMD_PTZ_UP_DOWN                 26
#define CMD_PTZ_UP_DOWN_STOP            27
#define CMD_PTZ_LEFT_RIGHT              28
#define CMD_PTZ_LEFT_RIGHT_STOP         29


#define CMD_PTZ_PREFAB_BIT_SET0         30
#define CMD_PTZ_PREFAB_BIT_SET1         32
#define CMD_PTZ_PREFAB_BIT_SET2         34
#define CMD_PTZ_PREFAB_BIT_SET3         36
#define CMD_PTZ_PREFAB_BIT_SET4         38
#define CMD_PTZ_PREFAB_BIT_SET5         40
#define CMD_PTZ_PREFAB_BIT_SET6         42
#define CMD_PTZ_PREFAB_BIT_SET7         44
#define CMD_PTZ_PREFAB_BIT_SET8         46
#define CMD_PTZ_PREFAB_BIT_SET9         48
#define CMD_PTZ_PREFAB_BIT_SETA         50
#define CMD_PTZ_PREFAB_BIT_SETB         52
#define CMD_PTZ_PREFAB_BIT_SETC         54
#define CMD_PTZ_PREFAB_BIT_SETD         56
#define CMD_PTZ_PREFAB_BIT_SETE         58
#define CMD_PTZ_PREFAB_BIT_SETF         60

#define CMD_PTZ_PREFAB_BIT_RUN0         31
#define CMD_PTZ_PREFAB_BIT_RUN1         33
#define CMD_PTZ_PREFAB_BIT_RUN2         35
#define CMD_PTZ_PREFAB_BIT_RUN3         37
#define CMD_PTZ_PREFAB_BIT_RUN4         39
#define CMD_PTZ_PREFAB_BIT_RUN5         41
#define CMD_PTZ_PREFAB_BIT_RUN6         43
#define CMD_PTZ_PREFAB_BIT_RUN7         45
#define CMD_PTZ_PREFAB_BIT_RUN8         47
#define CMD_PTZ_PREFAB_BIT_RUN9         49
#define CMD_PTZ_PREFAB_BIT_RUNA         51
#define CMD_PTZ_PREFAB_BIT_RUNB         53
#define CMD_PTZ_PREFAB_BIT_RUNC         55
#define CMD_PTZ_PREFAB_BIT_RUND         57
#define CMD_PTZ_PREFAB_BIT_RUNE         59
#define CMD_PTZ_PREFAB_BIT_RUNF         61


#ifndef _DEF_STRU_AV_HEAD
#define _DEF_STRU_AV_HEAD
typedef struct tag_AV_HEAD
{
    unsigned int   		startcode;	//  0xa815aa55
    unsigned char		type;		//  0->264 idr frame 1->264 p frame
    unsigned char  	    streamid;	
    unsigned short  	militime;	//  diff time
    unsigned int 		sectime;	//  diff time
    unsigned int    	frameno;	//  frameno
    unsigned int 		len;		//  data len
    unsigned char		version;	// version
    unsigned char		sessid;		//ssid
    unsigned char		other[2];
    unsigned char		other1[8];
}AV_HEAD,*PAV_HEAD;
#endif

typedef struct tag_STRU_CAMERA_PARAMS
{
    int resolution;
    int brightness;
    int contrast;
    int hue;
    int saturation;
    int flip;
}STRU_CAMERA_PARAMS,*PSTRU_CAMERA_PARAMS;


typedef struct tag_STRU_CAMERA_CONTROL
{
    int param;
    int value;
}STRU_CAMERA_CONTROL,*PSTRU_CAMERA_CONTROL;


typedef struct tag_STRU_NETWORK_PARAMS
{
    char ipaddr[64];
    char netmask[64];
    char gateway[64];
    char dns1[64];
    char dns2[64];
    int dhcp;
    int port;
    int rtspport;
}STRU_NETWORK_PARAMS,*PSTRU_NETWORK_PARAMS;

typedef struct tag_STRU_USER_INFO
{
    char user1[64];
    char pwd1[64];
    char user2[64];
    char pwd2[64];
    char user3[64];
    char pwd3[64];
}STRU_USER_INFO,*PSTRU_USER_INFO;


typedef struct tag_STRU_WIFI_PARAMS
{
    int enable;
    char ssid[128];
    int channel;
    int mode;
    int authtype;
    int encrypt;
    int keyformat;
    int defkey;
    char key1[128];
    char key2[128];
    char key3[128];
    char key4[128];
    int key1_bits;
    int key2_bits;
    int key3_bits;
    int key4_bits;
    char wpa_psk[128];
}STRU_WIFI_PARAMS,*PSTRU_WIFI_PARAMS;


typedef struct tag_STRU_DATETIME_PARAMS
{
    int now;
    int tz;
    int ntp_enable;
    char ntp_svr[64];
}STRU_DATETIME_PARAMS,*PSTRU_DATETIME_PARAMS;


typedef struct tag_STRU_DDNS_PARAMS
{
    int service;
    char user[64];
    char pwd[64];
    char host[64];
    char proxy_svr[64];
    int ddns_mode;
    int proxy_port;
    int ddns_status;
}STRU_DDNS_PARAMS,*PSTRU_DDNS_PARAMS;


typedef struct tag_STRU_FTP_PARAMS
{
    char svr_ftp[64];
    char user[64];
    char pwd[64];
    char dir[128];
    int port;
    int mode;
    int upload_interval;
}STRU_FTP_PARAMS,*PSTRU_FTP_PARAMS;

typedef struct tag_STRU_MAIL_PARAMS
{
    char svr[64];    
    char user[64];    
    char pwd[64];
    char sender[64];
    char receiver1[64];
    char receiver2[64];
    char receiver3[64];
    char receiver4[64];
    int port;
    int ssl;
}STRU_MAIL_PARAMS,*PSTRU_MAIL_PARAMS;

typedef struct tag_STRU_ALARM_PARAMS
{
    int motion_armed;
    int motion_sensitivity;
    int input_armed;
    int ioin_level;
    int iolinkage;
    int ioout_level;
    int alarmpresetsit;
    int mail;
    int snapshot;
    int record;
    int upload_interval;
    int schedule_enable;
    int schedule_sun_0;
    int schedule_sun_1;
    int schedule_sun_2;
    int schedule_mon_0;
    int schedule_mon_1;
    int schedule_mon_2;
    int schedule_tue_0;
    int schedule_tue_1;
    int schedule_tue_2;
    int schedule_wed_0;
    int schedule_wed_1;
    int schedule_wed_2;
    int schedule_thu_0;
    int schedule_thu_1;
    int schedule_thu_2;
    int schedule_fri_0;
    int schedule_fri_1;
    int schedule_fri_2;
    int schedule_sat_0;
    int schedule_sat_1;
    int schedule_sat_2;
}STRU_ALARM_PARAMS,*PSTRU_ALARM_PARAMS;

typedef struct tag_STRU_PTZ_PARAMS
{
    int led_mode;
    int ptz_center_onstart;
    int ptz_run_times;
    int ptz_patrol_rate;
    int ptz_patrol_up_rate;
    int ptz_patrol_down_rate;
    int ptz_patrol_left_rate;
    int ptz_patrol_right_rate;
    int disable_preset;
    int ptz_preset;
}STRU_PTZ_PARAMS,*PSTRU_PTZ_PARAMS;

typedef struct tag_STRU_CAMERA_STATUS
{
    char sysver[32];
    char devname[96];
    char devid[32];
    int alarmstatus;
    int sdcardstatus;
    int sdcardtotalsize;
    int sdcardremainsize;
    char mac[32];
    char wifimac[32];
    int dns_status;
    int upnp_status;
}STRU_CAMERA_STATUS,*PSTRU_CAMERA_STATUS;

typedef struct tag_STRU_WIFI_SEARCH_RESULT
{
    char ssid[64];
    char mac[64];
    int security;
    char dbm0[32];
    char  dbm1[32];
    int mode;
    int channel;

}STRU_WIFI_SEARCH_RESULT,*PSTRU_WIFI_SEARCH_RESULT;


typedef struct tag_STRU_WIFI_SEARCH_RESULT_LIST
{
    int nResultCount;
    STRU_WIFI_SEARCH_RESULT wifi[50];
}STRU_WIFI_SEARCH_RESULT_LIST,*PSTRU_WIFI_SEARCH_RESULT_LIST;

typedef struct tag_STRU_GET_RECORD_FILE_PARAM
{
    int PageIndex;
    int PageSize;
}STRU_GET_RECORD_FILE_PARAM,*PSTRU_GET_RECORD_FILE_PARAM;

typedef struct tag_STRU_PLAY_BACK_PARAM
{
    char filename[128];
    int pos;
}STRU_PLAY_BACK_PARAM,*PSTRU_PLAY_BACK_PARAM;

typedef struct tag_STRU_SDCARD_RECORD_FILE
{
    char szFileName[128];
    int nFileSize;
}STRU_SDCARD_RECORD_FILE,PSTRU_SDCARD_RECORD_FILE;

#define MAX_RECORD_FILE_COUNT 128
typedef struct tag_STRU_RECORD_FILE_LIST
{
    int nCount;
    int nRecordCount;
    int nPageCount;
    int nPageIndex;
    int nPageSize;
    STRU_SDCARD_RECORD_FILE recordFile[MAX_RECORD_FILE_COUNT];

}STRU_RECORD_FILE_LIST, PSTRU_RECORD_FILE_LIST;

typedef struct  tag_STRU_SD_RECORD_PARAM
{
    int record_cover_enable; 
    int record_timer; 
    int record_size;
    int record_time_enable; 
    int record_schedule_sun_0;
    int record_schedule_sun_1; 
    int record_schedule_sun_2; 
    int record_schedule_mon_0; 
    int record_schedule_mon_1; 
    int record_schedule_mon_2; 
    int record_schedule_tue_0; 
    int record_schedule_tue_1; 
    int record_schedule_tue_2; 
    int record_schedule_wed_0;
    int record_schedule_wed_1; 
    int record_schedule_wed_2; 
    int record_schedule_thu_0; 
    int record_schedule_thu_1; 
    int record_schedule_thu_2; 
    int record_schedule_fri_0; 
    int record_schedule_fri_1; 
    int record_schedule_fri_2; 
    int record_schedule_sat_0; 
    int record_schedule_sat_1; 
    int record_schedule_sat_2; 
    int record_sd_status; 
    int sdtotal;
    int sdfree; 

}STRU_SD_RECORD_PARAM, *PSTRU_SD_RECORD_PARAM;



#endif