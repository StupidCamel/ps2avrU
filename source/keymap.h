#ifndef KEYMAP_H
#define KEYMAP_H

#include <stdbool.h>
#include <avr/pgmspace.h>

#define KFLA_EXTEND         0x01
#define KFLA_SPECIAL        0x02
#define KFLA_MAKEONLY       0x04
#define KFLA_MAKE_BREAK     0x08
#define KFLA_PROC_SHIFT     0x10

// Total 
#define NUM_KEY 176     // 0~

// fn
#define KEY_FN          254
#define KEY_LED         253
#define KEY_BEYOND_FN   252     // fn2 toggle
#define KEY_NOR         251         // beyond_fn에서 0 레이어로 점프, 0레이어의 같은 위치의 키값도 전송된다.
#define KEY_LED_UP      250     // increase led brightness 
#define KEY_LED_DOWN    249     // reduce led brightness
#define KEY_FN2         248
#define KEY_P2U         247
#define KEY_FN3         246
// #define KEY_P2U_RESET   245
#define KEY_LOCK_ALL    244
#define KEY_LOCK_WIN    243

// dual action 
enum {
    KEY_dualAction = 213,
    KEY_FN_HANGLE,      // 누른 상태에서 다른 키를 조합하면 Fn키로 작동하고 아니면 한/영키로 작동;
    KEY_FN_HANJA,
    KEY_FN2_HANGLE,
    KEY_FN2_HANJA,
    KEY_RSHIFT_HANGLE,
    KEY_RSHIFT_HANJA,
    KEY_LSHIFT_HANGLE,
    KEY_LSHIFT_HANJA,
    KEY_RALT_HANGLE,
    KEY_RALT_HANJA,
    KEY_LALT_HANGLE,
    KEY_LALT_HANJA,
    KEY_RCTRL_HANGLE,
    KEY_RCTRL_HANJA,
    KEY_LCTRL_HANGLE,
    KEY_LCTRL_HANJA,
    KEY_FN_CAPS,
    KEY_FN2_CAPS,
    KEY_FN3_HANGLE,
    KEY_FN3_HANJA,
    KEY_FN3_CAPS,
    KEY_dualAction_end  // 235
};

enum {  // for macro
    KEY_MAC1 = 201,
    KEY_MAC2,
    KEY_MAC3,
    KEY_MAC4,
    KEY_MAC5,
    KEY_MAC6,
    KEY_MAC7,
    KEY_MAC8,
    KEY_MAC9,
    KEY_MAC10,
    KEY_MAC11,
    KEY_MAC12   // 212
};

#define KEY_MAX         KEY_MAC1   // 이 값보다 크거나 같으면 키인덱스를 처리 하지 않는다.


enum {
	KEY_NONE = 0,     // unused
    KEY_ErrorRollOver,
    KEY_POSTFail,
    KEY_ErrorUndefined,

    KEY_A,                // 0x04
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,

    KEY_K,
    KEY_L,
    KEY_M,                // 0x10
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,

    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_1,                //       1 and !
    KEY_2,                //       2 and @
    KEY_3,                // 0x20  3 and #
    KEY_4,                //       4 and $

    KEY_5,                //       5 and %
    KEY_6,                //       6 and ^
    KEY_7,                //       7 and &
    KEY_8,                //       8 and *
    KEY_9,                //       9 and (
    KEY_0,                // 0x27  0 and )
    KEY_ENTER,           // 0x28  enter
    KEY_ESC,           // 0x29
    KEY_BKSP,           // 0x2A  backspace
    KEY_TAB,              // 0x2B

    KEY_SPACE,         // 0x2C
    KEY_MINUS,            // 0x2D  - and _
    KEY_EQUAL,           // 0x2E  = and +
    KEY_LBR,         // 0x2F  [ and {
    KEY_RBR,         // 0x30  ] and }
    KEY_BKSLASH,        // 0x31  \ and |
    KEY_Europe1,             // 0x32  non-US # and ~
    KEY_COLON,        // 0x33  ; and :
    KEY_QUOTE,        // 0x34  ' and "
    KEY_HASH,            // 0x35  grave accent and tilde

    KEY_COMMA,            // 0x36  , and <
    KEY_DOT,              // 0x37  . and >
    KEY_SLASH,            // 0x38  / and ?
    KEY_CAPS,         // 0x39
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,

    KEY_F7,               // 0x40
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_PRNSCR,
    KEY_SCRLCK,
    KEY_PAUSE,            //       Break
    KEY_INSERT,

    KEY_HOME,
    KEY_PGUP,
    KEY_DEL,
    KEY_END,
    KEY_PGDN,
    KEY_RIGHT,
    KEY_LEFT,        // 0x50
    KEY_DOWN,
    KEY_UP,
    KEY_NUMLOCK,          //       Clear

    KEY_KP_SLASH,
    KEY_KP_AST,
    KEY_KP_MINUS,
    KEY_KP_PLUS,
    KEY_KP_ENTER,
    KEY_KP_1,              //       End
    KEY_KP_2,              //       Down Arrow
    KEY_KP_3,              //       Page Down
    KEY_KP_4,              //       Left Arrow
    KEY_KP_5,

    KEY_KP_6,              //       Right Arrow
    KEY_KP_7,              //       Home
    KEY_KP_8,              // 0x60  Up Arrow
    KEY_KP_9,              //       Page Up
    KEY_KP_0,              //       Insert
    KEY_KP_DOT,          //       Delete
    KEY_Europe2,             //       non-US \ and |
    KEY_APPS,		// 101 (0x65)

	 /* These are NOT standard USB HID - handled specially in decoding, 
     so they will be mapped to the modifier byte in the USB report */
	KEY_Modifiers, // 102
	KEY_LCTRL,    // 0x01
	KEY_LSHIFT,   // 0x02
	KEY_LALT,     // 0x04
	KEY_LGUI,     // 0x08
	KEY_RCTRL,    // 0x10
	KEY_RSHIFT,   // 0x20
	KEY_RALT,     // 0x40
	KEY_RGUI,     // 0x80
	KEY_Modifiers_end, // 111 (0x6F)

	KEY_Multimedia,
	KEY_POWER,	KEY_SLEEP,	KEY_WAKE, KEY_EMAIL, KEY_WWW_SEARCH, KEY_WWW_HOME, KEY_WWW_BACK, KEY_WWW_FORWARD,	
	KEY_WWW_STOP, KEY_WWW_REFRESH, KEY_WWW_FAVORITE, KEY_NEXT_TRK, KEY_PREV_TRK, KEY_STOP, KEY_PLAY, KEY_MUTE, KEY_VOL_UP, KEY_VOL_DOWN,	
	KEY_MEDIA,	KEY_CALC,	KEY_MYCOM,	KEY_SCREENSAVE,	KEY_REC, KEY_REWIND, KEY_MINIMIZE, KEY_EJECT,
 	KEY_Multimedia_end,

    KEY_extend,     // 140
    KEY_HANJA,  
    KEY_HANGLE, 
    KEY_KBD_POWER, 
    KEY_KP_EQUAL,
    KEY_F13,
    KEY_F14,
    KEY_F15,
    KEY_F16,
    KEY_F17,
    KEY_F18,            // 150
    KEY_F19,
    KEY_F20,
    KEY_F21,
    KEY_F22,
    KEY_F23,
    KEY_F24,     
    KEY_KP_COMMA,
    KEY_EQUAL_SIGN, 
    KEY_INT1,
    KEY_INT2,           // 160
    KEY_INT3,
    KEY_INT4,
    KEY_INT5,
    KEY_INT6,
    KEY_INT7,
    KEY_INT8,
    KEY_INT9,
    // KEY_LANG1,   /* = KEY_HANGLE       */
    // KEY_LANG2,   /* = KEY_HANJA      */
    KEY_LANG3,          
    KEY_LANG4,
    KEY_LANG5,          // 170
    KEY_LANG6,          
    KEY_LANG7,
    KEY_LANG8,
    KEY_LANG9,                
    KEY_extend_end    // 175
};

// for ps/2 interface
extern const uint8_t PROGMEM keycode_set2[NUM_KEY];

// usage page 01(Generic Desktop) : KEY_POWER,  KEY_SLEEP,  KEY_WAKE
// usage page 07(keyboard) : KEY_HANJA,   KEY_HANGLE, KEY_KBD_POWER
/* usage page 0C(Consumer Devices) : KEY_WWW_SEARCH, KEY_WWW_HOME, KEY_WWW_BACK, KEY_WWW_FORWARD, KEY_WWW_STOP, KEY_WWW_REFRESH, KEY_WWW_FAVORITE,KEY_EMAIL,  
                                    KEY_NEXT_TRK, KEY_PREV_TRK, KEY_STOP, KEY_PLAY, KEY_MUTE, KEY_VOL_UP, KEY_VOL_DOWN, KEY_MEDIA,  KEY_CALC,   KEY_MYCOM */
//
// windows OS 에서 미지원 키 : KEY_SCREENSAVE,    KEY_REC,    KEY_REWIND,     KEY_MINIMIZE,   KEY_EJECT

extern const uint16_t PROGMEM keycode_USB_multimedia[];
// KEY_APPS까지는 keycode 순서에 맞게 나열되어 있지만, 
// KEY_extend는 배열 순서와는 다른 키코드를 갖는 usage page 07(keyboard)의 키코드를 정의.
extern const uint8_t PROGMEM keycode_USB_extend[];

extern const uint8_t PROGMEM keycode_set2_special[];

extern const uint8_t PROGMEM keycode_set2_makeonly[];

extern const uint8_t PROGMEM keycode_set2_make_break[];

extern const uint8_t PROGMEM keycode_set2_extend[];

extern const uint8_t PROGMEM keycode_set2_proc_shift[] ;

extern const unsigned short int modmask[8];

#endif
