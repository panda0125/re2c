/* Generated by re2c */

#include <stdio.h>
#include <stdlib.h> /* malloc, free */
#include <string.h> /* memcpy */

static void *read_file
    ( const char *fname
    , size_t unit
    , size_t padding
    , size_t *pfsize
    )
{
    void *buffer = NULL;
    size_t fsize = 0;

    /* open file */
    FILE *f = fopen(fname, "rb");
    if(f == NULL) {
        goto error;
    }

    /* get file size */
    fseek(f, 0, SEEK_END);
    fsize = (size_t) ftell(f) / unit;
    fseek(f, 0, SEEK_SET);

    /* allocate memory for file and padding */
    buffer = malloc(unit * (fsize + padding));
    if (buffer == NULL) {
        goto error;
    }

    /* read the whole file in memory */
    if (fread(buffer, unit, fsize, f) != fsize) {
        goto error;
    }

    fclose(f);
    *pfsize = fsize;
    return buffer;

error:
    fprintf(stderr, "error: cannot read file '%s'\n", fname);
    free(buffer);
    if (f != NULL) {
        fclose(f);
    }
    return NULL;
}

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line110
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line110: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line110: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line110(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line110: not enough keys\n");
    return 1;
}

int lex_line110()
{
    const size_t padding = 2; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("calc_008.b--skeleton.c.line110.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("calc_008.b--skeleton.c.line110.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        YYCTYPE yych;
        static const unsigned char yybm[] = {
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,  64,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
             64,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
            128, 128, 128, 128, 128, 128, 128, 128, 
            128, 128,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0, 
        };

        if (YYLESSTHAN (2)) YYFILL(2);
        yych = YYPEEK ();
        if (yybm[0+yych] & 64) {
            goto yy6;
        }
        if (yych <= ',') {
            if (yych <= 0x00) goto yy2;
            if (yych == '+') goto yy9;
            goto yy4;
        } else {
            if (yych <= '/') {
                if (yych <= '-') goto yy11;
                goto yy4;
            } else {
                if (yych <= '0') goto yy13;
                if (yych <= '9') goto yy15;
                goto yy4;
            }
        }
yy2:
        YYSKIP ();
        status = check_key_count_line110(keys_count, i, 3)
             || action_line110(&i, keys, input, token, &cursor, 5);
        continue;
yy4:
        YYSKIP ();
        status = check_key_count_line110(keys_count, i, 3)
             || action_line110(&i, keys, input, token, &cursor, 6);
        continue;
yy6:
        YYSKIP ();
        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yybm[0+yych] & 64) {
            goto yy6;
        }
        status = check_key_count_line110(keys_count, i, 3)
             || action_line110(&i, keys, input, token, &cursor, 0);
        continue;
yy9:
        YYSKIP ();
        status = check_key_count_line110(keys_count, i, 3)
             || action_line110(&i, keys, input, token, &cursor, 3);
        continue;
yy11:
        YYSKIP ();
        status = check_key_count_line110(keys_count, i, 3)
             || action_line110(&i, keys, input, token, &cursor, 4);
        continue;
yy13:
        YYSKIP ();
        yych = YYPEEK ();
        if (yych <= '/') goto yy14;
        if (yych <= '9') goto yy17;
yy14:
        status = check_key_count_line110(keys_count, i, 3)
             || action_line110(&i, keys, input, token, &cursor, 2);
        continue;
yy15:
        YYSKIP ();
        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yybm[0+yych] & 128) {
            goto yy15;
        }
        goto yy14;
yy17:
        YYSKIP ();
        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych <= '/') goto yy19;
        if (yych <= '9') goto yy17;
yy19:
        status = check_key_count_line110(keys_count, i, 3)
             || action_line110(&i, keys, input, token, &cursor, 1);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line110: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line110: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

int main()
{
    if(lex_line110() != 0) {
        return 1;
    }
    return 0;
}
 
!"#$%&'()*,./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������		   		  		  		  		  
		  		  		  		  		  		  		  		  		  		  		  !		"  #		$  %		&  '		(  )		*  +		,  -		.  /		0  1		2  3		4  5		6  7		8  9		:  ;		<  =		>  ?		@  A		B  C		D  E		F  G		H  I		J  K		L  M		N  O		P  Q		R  S		T  U		V  W		X  Y		Z  [		\  ]		^  _		`  a		b  c		d  e		f  g		h  i		j  k		l  m		n  o		p  q		r  s		t  u		v  w		x  y		z  {		|  }		~  		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �		�  �	  	 	 	 	 
	 	 	 	 	 	 	 	 	 	 	 !	" #	$ %	& '	( )	* +	, -	. /	0 1	2 3	4 5	6 7	8 9	: ;	< =	> ?	@ A	B C	D E	F G	H I	J K	L M	N O	P Q	R S	T U	V W	X Y	Z [	\ ]	^ _	` a	b c	d e	f g	h i	j k	l m	n o	p q	r s	t u	v w	x y	z {	| }	~ 	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �	� �+-000 011022033044055066077088099	000
011022033044055066077088099000011022033044055066077088099000011022 033!044"055#066$077%088&099'000(011)022*033+044,055-066.077/088:099;000<011=022>033?044@055A066B077C088D099E000F011G022H033I044J055K066L077M088N099O000P011Q022R033S044T055U066V077W088X099Y000Z011[022\033]044^055_066`077a088b099c000d011e022f033g044h055i066j077k088l099m000n011o022p033q044r055s066t077u088v099w000x011y022z033{044|055}066~077088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�066�077�088�099�000�011�022�033�044�055�00 010203040506070809	00
01020304050607080900010203040506070809000102 03!04"05#06$07%08&09'00(01)02*03+04,05-06.07/08:09;00<01=02>03?04@05A06B07C08D09E00F01G02H03I04J05K06L07M08N09O00P01Q02R03S04T05U06V07W08X09Y00Z01[02\03]04^05_06`07a08b09c00d01e02f03g04h05i06j07k08l09m00n01o02p03q04r05s06t07u08v09w00x01y02z03{04|05}06~0708�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�06�07�08�09�00�01�02�03�04�05�0 000000000	0
0000000000000000000000 0!0"0#0$0%0&0'0(0)0*0+0,0-0.0/0:0;0<0=0>0?0@0A0B0C0D0E0F0G0H0I0J0K0L0M0N0O0P0Q0R0S0T0U0V0W0X0Y0Z0[0\0]0^0_0`0a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0{0|0}0~00�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�0�10 213243546576879819	20
31425364758697182930415263748596172839405162 73!84"95#16$27%38&49'50(61)72*83+94,15-26.37/48:59;60<71=82>93?14@25A36B47C58D69E70F81G92H13I24J35K46L57M68N79O80P91Q12R23S34T45U56V67W78X89Y90Z11[22\33]44^55_66`77a88b99c10d21e32f43g54h65i76j87k98l19m20n31o42p53q64r75s86t97u18v29w30x41y52z63{74|85}96~1728�39�40�51�62�73�84�95�16�27�38�49�50�61�72�83�94�15�26�37�48�59�60�71�82�93�14�25�36�47�58�69�70�81�92�13�24�35�46�57�68�79�80�91�12�23�34�45�56�67�78�89�90�11�22�33�44�55�66�77�88�99�10�21�32�43�54�65�76�87�98�19�20�31�42�53�64�75�86�97�18�29�30�41�52�63�74�85�96�17�28�39�40�51�62�73�84�95�16�27�38�49�50�61�72�83�94�15�26�37�48�59�60�71�82�93�14�25�36�47�58�69�70�81�92�13�24�35�1 234567891	2
3456789123456789123456 7!8"9#1$2%3&4'5(6)7*8+9,1-2.3/4:5;6<7=8>9?1@2A3B4C5D6E7F8G9H1I2J3K4L5M6N7O8P9Q1R2S3T4U5V6W7X8Y9Z1[2\3]4^5_6`7a8b9c1d2e3f4g5h6i7j8k9l1m2n3o4p5q6r7s8t9u1v2w3x4y5z6{7|8}9~12�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�4�5�6�7�8�9�1�2�3�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            