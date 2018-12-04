/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : FD constraint solver                                            *
 * File  : fd_to_c.h                                                       *
 * Descr.: FD to C macros - header file                                    *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/* $Id: fd_to_c.h,v 1.14 2009/01/23 11:24:14 diaz Exp $ */


#ifndef _FD_TO_C_H
#define _FD_TO_C_H

#include <stdio.h>

/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : Prolog engine                                                   *
 * File  : pl_params.h                                                     *
 * Descr.: parameter header file                                           *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/* $Id: pl_params.h,v 1.12 2009/01/23 11:24:14 diaz Exp $ */

#define MAX_OBJECT                 1024

#define START_PRED_TBL_SIZE        4096

#define START_OPER_TBL_SIZE        1024

#define ATOM_SIZE                  20
#define MAX_ATOM                   (1 << ATOM_SIZE) /* number of elements */

#define NB_OF_X_REGS               256
#define MAX_ARITY                  (NB_OF_X_REGS - 1)

/* NB: if NB_OF_X_REGS is changed it is necessary to modify ma2asm but
   also the byte code management */

/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : Prolog engine                                                   *
 * File  : wam_archi.def (gives rise to wam_archi.h)                       *
 * Descr.: Wam architecture definition - description file                  *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/*---------------------------------*
 * Register Descriptions           *
 *---------------------------------*/


typedef long WamWord;		/* a wamword is a long (32/64 bits) */

typedef void (*CodePtr) ();	/* a code pointer is a ptr to fct */

typedef CodePtr WamCont;	/* a continuation is a code pointer */

#ifndef ONLY_TAG_PART

#define X(x)                       (pl_reg_bank[x])
#define A(a)                       (pl_reg_bank[a])

typedef WamWord *WamWordP;




   /*--- Begin Register Generation ---*/

#define TR			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+0])
#define B			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+1])
#define H			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+2])
#define HB1			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+3])
#define CP			(((WamCont  *) pl_reg_bank)[NB_OF_X_REGS+4])
#define E			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+5])
#define CS			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+6])
#define S			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+7])
#define STAMP			(((WamWord  *) pl_reg_bank)[NB_OF_X_REGS+8])
#define BCI			(((WamWord  *) pl_reg_bank)[NB_OF_X_REGS+9])
#define LSSA			(((WamWordP *) pl_reg_bank)[NB_OF_X_REGS+10])


#define NB_OF_REGS          	11
#define NB_OF_ALLOC_REGS    	0
#define NB_OF_NOT_ALLOC_REGS	11
#define REG_BANK_SIZE       	(NB_OF_X_REGS+NB_OF_NOT_ALLOC_REGS)




#define NB_OF_USED_MACHINE_REGS 0

#ifdef ENGINE_FILE

WamWord pl_reg_bank[REG_BANK_SIZE];
char *pl_reg_tbl[] = { "TR", "B", "H", "HB1", "CP", "E", "CS", "S", "STAMP", "BCI", "LSSA"};

#else

extern WamWord pl_reg_bank[];
extern char *pl_reg_tbl[];

#endif

#define Init_Reg_Bank(x)


#define Reg(i)			(((i)==0) ? (WamWord) TR 	: \
				 ((i)==1) ? (WamWord) B  	: \
				 ((i)==2) ? (WamWord) H  	: \
				 ((i)==3) ? (WamWord) HB1	: \
				 ((i)==4) ? (WamWord) CP 	: \
				 ((i)==5) ? (WamWord) E  	: \
				 ((i)==6) ? (WamWord) CS 	: \
				 ((i)==7) ? (WamWord) S  	: \
				 ((i)==8) ? (WamWord) STAMP	: \
				 ((i)==9) ? (WamWord) BCI	: \
				            (WamWord) LSSA)




#define Save_All_Regs(buff_save) \
  do { \
    buff_save[0] = (WamWord) TR; \
    buff_save[1] = (WamWord) B; \
    buff_save[2] = (WamWord) H; \
    buff_save[3] = (WamWord) HB1; \
    buff_save[4] = (WamWord) CP; \
    buff_save[5] = (WamWord) E; \
    buff_save[6] = (WamWord) CS; \
    buff_save[7] = (WamWord) S; \
    buff_save[8] = (WamWord) STAMP; \
    buff_save[9] = (WamWord) BCI; \
    buff_save[10] = (WamWord) LSSA; \
  } while(0)




#define Restore_All_Regs(buff_save) \
  do { \
    TR     = (WamWordP) buff_save[0]; \
    B      = (WamWordP) buff_save[1]; \
    H      = (WamWordP) buff_save[2]; \
    HB1    = (WamWordP) buff_save[3]; \
    CP     = (WamCont ) buff_save[4]; \
    E      = (WamWordP) buff_save[5]; \
    CS     = (WamWordP) buff_save[6]; \
    S      = (WamWordP) buff_save[7]; \
    STAMP  = (WamWord ) buff_save[8]; \
    BCI    = (WamWord ) buff_save[9]; \
    LSSA   = (WamWordP) buff_save[10]; \
  } while(0)




#define Save_Machine_Regs(buff_save) \
  do { \
  } while(0)


#define Restore_Machine_Regs(buff_save) \
  do { \
  } while(0)




#define Start_Protect_Regs_For_Signal


#define Stop_Protect_Regs_For_Signal


#define Restore_Protect_Regs_For_Signal


   /*--- End Register Generation ---*/


#endif


/*---------------------------------*
 * Tag Descriptions                *
 *---------------------------------*/




   /*--- Begin Tag Generation ---*/

#define TAG_SIZE     		3
#define TAG_SIZE_LOW 		2
#define TAG_SIZE_HIGH		1
#define VALUE_SIZE   		29
#define TAG_MASK     		0x80000003UL
#define VALUE_MASK   		0x7ffffffcUL
#define Tag_Mask_Of(w)		((unsigned long) (w) & (TAG_MASK))
#define Tag_From_Tag_Mask(w) 	(((unsigned long) (w) >> 29) | ((w) & 3))
#define Tag_Of(w)     		((((unsigned long) (w) >> 31) << 2) | ((w) & 3))
#define TAG_REF_MASK		0UL
#define TAG_LST_MASK		0x1UL
#define TAG_STC_MASK		0x2UL
#define TAG_ATM_MASK		0x3UL
#define TAG_FLT_MASK		0x80000000UL
#define TAG_FDV_MASK		0x80000001UL
#define TAG_INT_MASK		0x80000003UL

#define NB_OF_TAGS       	7
#define REF        		0 
#define LST        		1 
#define STC        		2 
#define ATM        		3 
#define FLT        		4 
#define FDV        		5 
#define INT        		7 

	/* General Tag/UnTag macros */

#define Tag_Long_Int(tm, v)  	((((unsigned long) ((v) << 3)) >> 1) | (tm))
#define Tag_Short_Uns(tm, v)	(((unsigned long) (v) << 2) + (tm))
#define Tag_Address(tm, v)  	((unsigned long) (v) + (tm))

#define UnTag_Long_Int(w)    	((long) ((w) << 1) >> 3)
#define UnTag_Short_Uns(w)	UnTag_Long_Int(w)
#define UnTag_Address(w)  	((WamWord *) ((w) & VALUE_MASK))


	/* Specialized Tag/UnTag macros */


#define Tag_REF(v)  		Tag_Address(TAG_REF_MASK, v)
#define Tag_LST(v)  		Tag_Address(TAG_LST_MASK, v)
#define Tag_STC(v)  		Tag_Address(TAG_STC_MASK, v)
#define Tag_ATM(v)  		Tag_Short_Uns(TAG_ATM_MASK, v)
#define Tag_FLT(v)  		Tag_Address(TAG_FLT_MASK, v)
#define Tag_FDV(v)  		Tag_Address(TAG_FDV_MASK, v)
#define Tag_INT(v)  		(((unsigned long) (v) << 2) | TAG_MASK)

#define UnTag_REF(w)  		((WamWord *) (w))
#define UnTag_LST(w)  		UnTag_Address(w)
#define UnTag_STC(w)  		UnTag_Address(w)
#define UnTag_ATM(w)  		((unsigned long) (w) >> 2)
#define UnTag_FLT(w)  		UnTag_Address(w)
#define UnTag_FDV(w)  		UnTag_Address(w)
#define UnTag_INT(w)  		UnTag_Long_Int(w)

#define Tag_Is_REF(w)  		(Tag_Mask_Of(w) == TAG_REF_MASK)
#define Tag_Is_LST(w)  		(Tag_Mask_Of(w) == TAG_LST_MASK)
#define Tag_Is_STC(w)  		(Tag_Mask_Of(w) == TAG_STC_MASK)
#define Tag_Is_ATM(w)  		(Tag_Mask_Of(w) == TAG_ATM_MASK)
#define Tag_Is_FLT(w)  		(Tag_Mask_Of(w) == TAG_FLT_MASK)
#define Tag_Is_FDV(w)  		(Tag_Mask_Of(w) == TAG_FDV_MASK)
#define Tag_Is_INT(w)  		(Tag_Mask_Of(w) == TAG_INT_MASK)

typedef enum
{
  LONG_INT,
  SHORT_UNS,
  ADDRESS
}TypTag;

typedef struct
{
  char *name;
  TypTag type;
  int value;
  long tag_mask;
}InfTag;


#ifdef ENGINE_FILE

InfTag pl_tag_tbl[] =
{
  { "REF", ADDRESS, 0, 0UL },
  { "LST", ADDRESS, 1, 0x1UL },
  { "STC", ADDRESS, 2, 0x2UL },
  { "ATM", SHORT_UNS, 3, 0x3UL },
  { "FLT", ADDRESS, 4, 0x80000000UL },
  { "FDV", ADDRESS, 5, 0x80000001UL },
  { "INT", LONG_INT, 7, 0x80000003UL }
};

#else

extern InfTag pl_tag_tbl[];

#endif


   /*--- End Tag Generation ---*/





/*---------------------------------*
 * Stack Descriptions              *
 *---------------------------------*/

#ifndef ONLY_TAG_PART

#define KBytes_To_Wam_Words(kb)    ((1024 * kb + sizeof(WamWord) - 1) / sizeof(WamWord))

#define Wam_Words_To_KBytes(ww)    (ww * sizeof(WamWord) / 1024)

#define Local_Top                  ((B >= E) ? B : E)



   /*--- Begin Stack Generation ---*/

#define NB_OF_STACKS 		4

#define Trail_Stack       	(pl_stk_tbl[0].stack)
#define Trail_Size        	(pl_stk_tbl[0].size)
#define Trail_Offset(adr) 	((WamWord *)(adr) - Trail_Stack)
#define Trail_Used_Size   	Trail_Offset(TR)

#define Cstr_Stack       	(pl_stk_tbl[1].stack)
#define Cstr_Size        	(pl_stk_tbl[1].size)
#define Cstr_Offset(adr) 	((WamWord *)(adr) - Cstr_Stack)
#define Cstr_Used_Size   	Cstr_Offset(CS)

#define Global_Stack       	(pl_stk_tbl[2].stack)
#define Global_Size        	(pl_stk_tbl[2].size)
#define Global_Offset(adr) 	((WamWord *)(adr) - Global_Stack)
#define Global_Used_Size   	Global_Offset(H)

#define Local_Stack       	(pl_stk_tbl[3].stack)
#define Local_Size        	(pl_stk_tbl[3].size)
#define Local_Offset(adr) 	((WamWord *)(adr) - Local_Stack)
#define Local_Used_Size   	Local_Offset(Local_Top)


#define Stack_Top(s)       	(((s) == 0) ? TR : ((s) == 1) ? CS : ((s) == 2) ? H : Local_Top)

typedef struct
{
  char *name;
  char *env_var_name;
  long *p_def_size;
  int default_size; 	/* in WamWords */
  int size;         	/* in WamWords */
  WamWord *stack;
}InfStack;


#ifdef ENGINE_FILE

    /* these variables can be overwritten by top_comp.c (see stack size file) */
long pl_def_trail_size;
long pl_def_cstr_size;
long pl_def_global_size;
long pl_def_local_size;
long pl_fixed_sizes;

InfStack pl_stk_tbl[] =
{
 { "trail", "TRAILSZ", &pl_def_trail_size, 2097152, 0, NULL },
 { "cstr", "CSTRSZ", &pl_def_cstr_size, 2097152, 0, NULL },
 { "global", "GLOBALSZ", &pl_def_global_size, 4194304, 0, NULL },
 { "local", "LOCALSZ", &pl_def_local_size, 2097152, 0, NULL }
};

#else

extern long pl_def_trail_size;
extern long pl_def_cstr_size;
extern long pl_def_global_size;
extern long pl_def_local_size;
extern long pl_fixed_sizes;


extern InfStack pl_stk_tbl[];

#endif


   /*--- End Stack Generation ---*/


#endif
/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : FD constraint solver                                            *
 * File  : engine_fd.h                                                     *
 * Descr.: general header file                                             *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/* $Id: engine_fd.h,v 1.11 2009/01/23 11:24:14 diaz Exp $ */

/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : FD constraint solver                                            *
 * File  : fd_range.h                                                      *
 * Descr.: FD Range Implementation - header file                           *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/* $Id: fd_range.h,v 1.13 2009/01/23 11:24:14 diaz Exp $ */

/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : configuration                                                   *
 * File  : bool.h                                                          *
 * Descr.: boolean type definition - header file                           *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/* $Id: bool.h,v 1.12 2009/01/23 11:24:14 diaz Exp $ */

#ifndef _BOOL_H
#define _BOOL_H

#ifdef FALSE

#    if FALSE != 0
#        error "FALSE already defined with a value != 0"
#    endif
#else

#define FALSE 0

#endif

#ifdef TRUE

#    if TRUE != 1
#        error "TRUE already defined with a value != 1"
#    endif
#else

#define TRUE 1

#endif

#ifndef Bool
typedef int Bool;
#endif

#endif /* !_BOOL_H */

/*---------------------------------*
 * Constants                       *
 *---------------------------------*/

/*---------------------------------*
 * Type Definitions                *
 *---------------------------------*/

typedef unsigned long VecWord;

typedef VecWord *Vector;

typedef struct			/* Ranges are always handled through pointers */
{
  Bool extra_cstr;
  int min;
  int max;
  Vector vec;
}
Range;




/*---------------------------------*
 * Global Variables                *
 *---------------------------------*/

/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : FD constraint solver                                            *
 * File  : fd_hook_range.h                                                 *
 * Descr.: FD Range Implementation - customizable header file              *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/* $Id: fd_hook_range.h,v 1.12 2009/01/23 11:24:14 diaz Exp $ */

/*---------------------------------*
 * Constants                       *
 *---------------------------------*/

#define RANGE_TOP_STACK            CS
#define INTERVAL_MAX_INTEGER       ((int)((1L<<(32-TAG_SIZE-1))-1))	/* only 32 bits */

	  /* Default definitions (if not defined in fd_hook_range.h) */

#ifndef WORD_SIZE
#   define WORD_SIZE               32
#endif



#if WORD_SIZE == 32

#   define WORD_SIZE_BITS          5

#else

#   define WORD_SIZE_BITS          6

#endif




/*---------------------------------*
 * Function Prototypes             *
 *---------------------------------*/

int Pl_Least_Significant_Bit(VecWord x);

int Pl_Most_Significant_Bit(VecWord x);

void Pl_Define_Vector_Size(int max_val);

void Pl_Vector_From_Interval(Vector vec, int min, int max);

int Pl_Vector_Nb_Elem(Vector vec);

int Pl_Vector_Ith_Elem(Vector vec, int n);

int Pl_Vector_Next_After(Vector vec, int n);

int Pl_Vector_Next_Before(Vector vec, int n);

void Pl_Vector_Empty(Vector vec);

void Pl_Vector_Full(Vector vec);

Bool Pl_Vector_Test_Null_Inter(Vector vec, Vector vec1);

void Pl_Vector_Copy(Vector vec, Vector vec1);

void Pl_Vector_Union(Vector vec, Vector vec1);

void Pl_Vector_Inter(Vector vec, Vector vec1);

void Pl_Vector_Compl(Vector vec);

void Pl_Vector_Add_Vector(Vector vec, Vector vec1);

void Pl_Vector_Sub_Vector(Vector vec, Vector vec1);

void Pl_Vector_Mul_Vector(Vector vec, Vector vec1);

void Pl_Vector_Div_Vector(Vector vec, Vector vec1);

void Pl_Vector_Mod_Vector(Vector vec, Vector vec1);

void Pl_Vector_Add_Value(Vector vec, int n);

void Pl_Vector_Mul_Value(Vector vec, int n);

void Pl_Vector_Div_Value(Vector vec, int n);

void Pl_Vector_Mod_Value(Vector vec, int n);

Bool Pl_Range_Test_Value(Range *range, int n);

Bool Pl_Range_Test_Null_Inter(Range *range, Range *range1);

void Pl_Range_Copy(Range *range, Range *range1);

int Pl_Range_Nb_Elem(Range *range);

int Pl_Range_Ith_Elem(Range *range, int n);

int Pl_Range_Next_After(Range *range, int n);

int Pl_Range_Next_Before(Range *range, int n);

void Pl_Range_Set_Value(Range *range, int n);

void Pl_Range_Reset_Value(Range *range, int n);

void Pl_Range_Becomes_Sparse(Range *range);

void Pl_Range_From_Vector(Range *range);

void Pl_Range_Union(Range *range, Range *range1);

void Pl_Range_Inter(Range *range, Range *range1);

void Pl_Range_Compl(Range *range);

void Pl_Range_Add_Range(Range *range, Range *range1);

void Pl_Range_Sub_Range(Range *range, Range *range1);

void Pl_Range_Mul_Range(Range *range, Range *range1);

void Pl_Range_Div_Range(Range *range, Range *range1);

void Pl_Range_Mod_Range(Range *range, Range *range1);

void Pl_Range_Add_Value(Range *range, int n);

void Pl_Range_Mul_Value(Range *range, int n);

void Pl_Range_Div_Value(Range *range, int n);

void Pl_Range_Mod_Value(Range *range, int n);

char *Pl_Range_To_String(Range *range);




/*---------------------------------*
 * Vector Management Macros        *
 *---------------------------------*/

#define Word_No_And_Bit_No(w, b)   (((VecWord) (w) << WORD_SIZE_BITS)|\
                                     (VecWord) (b))
#define Word_No(n)                 ((VecWord) (n) >> WORD_SIZE_BITS)
#define Bit_No(n)                  ((n) & (((VecWord) 1 << WORD_SIZE_BITS)-1))



#define Vector_Test_Value(vec, n)  ((vec[Word_No(n)] & ((VecWord) 1 << Bit_No(n))) != 0)




#define Vector_Set_Value(vec, n)   (vec[Word_No(n)] |= ((VecWord) 1 << Bit_No(n)))




#define Vector_Reset_Value(vec, n) (vec[Word_No(n)] &= ~((VecWord) 1 << Bit_No(n)))




#define Vector_Allocate_If_Necessary(vec)	\
  do						\
    {						\
      if (vec == NULL)				\
	Vector_Allocate(vec);			\
    }						\
  while (0)




#define Vector_Allocate(vec)       		\
  do						\
    {						\
      vec = (Vector) RANGE_TOP_STACK;		\
      RANGE_TOP_STACK += pl_vec_size;		\
    }						\
  while (0)




	  /* To enumerate a vector use VECTOR_BEGIN_ENUM / VECTOR_END_ENUM *
	   * macros as follows:                                            *
	   * ...                                                           *
	   * VECTOR_BEGIN_ENUM(the_vector,vec_elem)                        *
	   *    your code (vec_elem contains the current range element)    *
	   * VECTOR_END_ENUM                                               */

#define VECTOR_BEGIN_ENUM(vec, vec_elem)                              	  \
{									  \
  Vector enum_end = vec + pl_vec_size, enum_i = vec;			  \
  int enum_j;								  \
  VecWord enum_word;							  \
									  \
  vec_elem = 0;								  \
  do									  \
    {									  \
      enum_word = *enum_i;						  \
      for (enum_j = 0; enum_j++ < WORD_SIZE; enum_word >>= 1, vec_elem++) \
	{								  \
	  if (enum_word & 1)						  \
	    {


#define VECTOR_END_ENUM                                              	\
	    }								\
	}								\
    }									\
  while (++enum_i < enum_end);						\
}




/*---------------------------------*
 * Range Management Macros         *
 *---------------------------------*/

#define Is_Interval(range)         ((range)->vec == NULL)
#define Is_Sparse(range)           ((range)->vec != NULL)
#define Is_Empty(range)            ((range)->min >  (range)->max)
#define Is_Not_Empty(range)        ((range)->max >= (range)->min)


#define Set_To_Empty(range) (range)->max = (int)(1 << (sizeof(int) * 8 - 1))


#define Range_Init_Interval(range, r_min, r_max)	\
  do							\
    {							\
      (range)->extra_cstr = FALSE;			\
      (range)->min = (r_min);				\
      (range)->max = (r_max);				\
      (range)->vec = NULL;				\
    }							\
  while (0)

/*-------------------------------------------------------------------------*
 * GNU Prolog                                                              *
 *                                                                         *
 * Part  : FD constraint solver                                            *
 * File  : fd_inst.h                                                       *
 * Descr.: FD instruction implementation - header file                     *
 * Author: Daniel Diaz                                                     *
 *                                                                         *
 * Copyright (C) 1999-2009 Daniel Diaz                                     *
 *                                                                         *
 * GNU Prolog is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2, or any later version.       *
 *                                                                         *
 * GNU Prolog is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc.  *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.               *
 *-------------------------------------------------------------------------*/

/* $Id: fd_inst.h,v 1.15 2009/01/23 11:24:14 diaz Exp $ */

/*---------------------------------*
 * Constants                       *
 *---------------------------------*/

	  /* FD Variable Frame */

#define FD_VARIABLE_FRAME_SIZE     (OFFSET_RANGE+RANGE_SIZE+CHAINS_SIZE)
#define FD_INT_VARIABLE_FRAME_SIZE (OFFSET_RANGE+RANGE_SIZE)

#define OFFSET_RANGE               5
#define RANGE_SIZE                 (2+(sizeof(Range)/sizeof(WamWord)))

#define OFFSET_CHAINS              (OFFSET_RANGE+RANGE_SIZE)
#define CHAINS_SIZE                8



#define FD_Tag_Value(fdv_adr)      (((WamWord *) fdv_adr)[0])
#define FD_INT_Date(fdv_adr)       (((WamWord *) fdv_adr)[1])

#define Queue_Date_At_Push(fdv_adr)(((WamWord *) fdv_adr)[2])
#define Queue_Propag_Mask(fdv_adr) (((WamWord *) fdv_adr)[3])
#define Queue_Next_Fdv_Adr(fdv_adr)(((WamWord *) fdv_adr)[4])

#define Range_Stamp(fdv_adr)       (((WamWord *) fdv_adr)[OFFSET_RANGE])
#define Nb_Elem(fdv_adr)           (((WamWord *) fdv_adr)[OFFSET_RANGE+1])
#define Range(fdv_adr)             ((Range *) ((WamWord *) fdv_adr+OFFSET_RANGE+2))

#define Chains_Stamp(fdv_adr)      (((WamWord *) fdv_adr)[OFFSET_CHAINS])
#define Nb_Cstr(fdv_adr)           (((WamWord *) fdv_adr)[OFFSET_CHAINS+1])
#define Chains_Mask(fdv_adr)       (((WamWord *) fdv_adr)[OFFSET_CHAINS+2])
#define Chain_Min(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+3])
#define Chain_Max(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+4])
#define Chain_Min_Max(fdv_adr)     (((WamWord *) fdv_adr)[OFFSET_CHAINS+5])
#define Chain_Dom(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+6])
#define Chain_Val(fdv_adr)         (((WamWord *) fdv_adr)[OFFSET_CHAINS+7])




	  /* Shorthands for Range(fdv_adr)'s fields */

#define Extra_Cstr(fdv_adr)        (Range(fdv_adr)->extra_cstr)
#define Min(fdv_adr)               (Range(fdv_adr)->min)
#define Max(fdv_adr)               (Range(fdv_adr)->max)
#define Vec(fdv_adr)               (Range(fdv_adr)->vec)




	  /* Chain / Propagation Mask */


#define CHAIN_NB_MIN               0
#define CHAIN_NB_MAX               1
#define CHAIN_NB_MIN_MAX           2
#define CHAIN_NB_DOM               3
#define CHAIN_NB_VAL               4

#define MASK_EMPTY                 0
#define MASK_MIN                   1
#define MASK_MAX                   2
#define MASK_MIN_MAX               4
#define MASK_DOM                   8
#define MASK_VAL                   16


#define Has_Min_Mask(mask)         ((mask) & MASK_MIN)
#define Has_Max_Mask(mask)         ((mask) & MASK_MAX)
#define Has_Min_Max_Mask(mask)     ((mask) & MASK_MIN_MAX)
#define Has_Dom_Mask(mask)         ((mask) & MASK_DOM)
#define Has_Val_Mask(mask)         ((mask) & MASK_VAL)


#define Set_Min_Mask(mask)         ((mask) |= MASK_MIN)
#define Set_Max_Mask(mask)         ((mask) |= MASK_MAX)
#define Set_Min_Max_Mask(mask)     ((mask) |= MASK_MIN_MAX)
#define Set_Dom_Mask(mask)         ((mask) |= MASK_DOM)
#define Set_Val_Mask(mask)         ((mask) |= MASK_VAL)




	  /* Chain Record Frame */

#define CHAIN_RECORD_FRAME_SIZE    2

#define CF_Pointer(rec_adr)        (*(WamWord **) &(rec_adr[0]))
#define Next_Chain(rec_adr)        (*(WamWord **) &(rec_adr[1]))




	  /* Constraint Frame */

#define CONSTRAINT_FRAME_SIZE      3

#define OFFSET_OF_OPTIM_POINTER    1	/* this offset must corresponds to */

#define AF_Pointer(cf)             (*(WamWord **)  &(cf[0]))
#define Optim_Pointer(cf)          (*(WamWord **)  &(cf[1]))	/* this cell */
#define Cstr_Address(cf)           (*(long (**)()) &(cf[2]))




	  /* Miscellaneous */

#define ENV_VAR_VECTOR_MAX         "VECTORMAX"
#define DEFAULT_VECTOR_MAX         127


#define Fd_Variable_Is_Ground(fdv_adr) (Tag_Of(FD_Tag_Value(fdv_adr))==INT)




#define math_min(x, y)             ((x) <= (y) ? (x) : (y))
#define math_max(x, y)             ((x) >= (y) ? (x) : (y))




/*---------------------------------*
 * Type Definitions                *
 *---------------------------------*/

/*---------------------------------*
 * Global Variables                *
 *---------------------------------*/

#ifdef FD_INST_FILE

WamWord pl_vec_size;
WamWord pl_vec_max_integer;

#else

extern WamWord pl_vec_size;
extern WamWord pl_vec_max_integer;

#endif




/*---------------------------------*
 * Function Prototypes             *
 *---------------------------------*/

WamWord *Pl_Fd_Prolog_To_Fd_Var(WamWord arg_word, Bool pl_var_ok);

Range *Pl_Fd_Prolog_To_Range(WamWord list_word);

int Pl_Fd_Prolog_To_Value(WamWord arg_word);

WamWord *Pl_Fd_Prolog_To_Array_Int(WamWord list_word);

WamWord *Pl_Fd_Prolog_To_Array_Any(WamWord list_word);

WamWord *Pl_Fd_Prolog_To_Array_Fdv(WamWord list_word, Bool pl_var_ok);

void Pl_Fd_List_Int_To_Range(Range *range, WamWord list_word);

WamWord *Pl_Fd_New_Variable(void);

WamWord *Pl_Fd_New_Bool_Variable(void);

WamWord *Pl_Fd_New_Int_Variable(int n);

WamWord *Pl_Fd_Create_C_Frame(long (*cstr_fct) (), WamWord *AF,
			   WamWord *fdv_adr, Bool optim2);

void Pl_Fd_Add_Dependency(WamWord *fdv_adr, int chain_nb, WamWord *CF);

void Pl_Fd_Add_List_Dependency(WamWord *array, int chain_nb, WamWord *CF);



void Pl_Fd_Before_Add_Cstr(void);

Bool Pl_Fd_After_Add_Cstr(void);

void Pl_Fd_Stop_Constraint(WamWord *CF);



Bool Pl_Fd_Tell_Value(WamWord *fdv_adr, int n);

Bool Pl_Fd_Tell_Not_Value(WamWord *fdv_adr, int n);

Bool Pl_Fd_Tell_Int_Range(WamWord *fdv_adr, Range *range);

Bool Pl_Fd_Tell_Interv_Interv(WamWord *fdv_adr, int min, int max);

Bool Pl_Fd_Tell_Range_Range(WamWord *fdv_adr, Range *range);

void Pl_Fd_Display_Extra_Cstr(WamWord *fdv_adr);



void Pl_Fd_Init_Solver0(void);

void Pl_Fd_Reset_Solver0(void);

Bool Pl_Fd_Assign_Value(WamWord *fdv_adr, int n);

Bool Pl_Fd_Unify_With_Integer0(WamWord *fdv_adr, int n);

Bool Pl_Fd_Unify_With_Fd_Var0(WamWord *fdv_adr1, WamWord *fdv_adr2);

Bool Pl_Fd_Use_Vector(WamWord *fdv_adr);

Bool Pl_Fd_Check_For_Bool_Var(WamWord x_word);

int Pl_Fd_Variable_Size0(WamWord *fdv_adr);

int Pl_Fd_Copy_Variable0(WamWord *dst_adr, WamWord *fdv_adr);

char *Pl_Fd_Variable_To_String0(WamWord *fdv_adr);




#define Fd_Deref_Check_Fd_Var(fdv_word, word, tag_mask)         \
  DEREF(fdv_word, word, tag_mask);                              \
  if (tag_mask == TAG_REF_MASK)                                 \
    Pl_Err_Instantiation();                                     \
                                                                \
  if (tag_mask != TAG_INT_MASK && tag_mask != TAG_FDV_MASK)     \
    Pl_Err_Type(pl_type_fd_variable, word)




/*---------------------------------*
 * Constants                       *
 *---------------------------------*/



	  /* Environment Frame */

#define Frame_Variable(fv)         ((WamWord *)(AF[fv]))
#define Frame_Range_Parameter(fp)  ((Range *)  (AF[fp]))
#define Frame_Term_Parameter(fp)   ((int)      (AF[fp]))
#define Frame_List_Parameter(fp)   ((WamWord *)(AF[fp]))


#define chain_min                  CHAIN_NB_MIN
#define chain_max                  CHAIN_NB_MAX
#define chain_min_max              CHAIN_NB_MIN_MAX
#define chain_dom                  CHAIN_NB_DOM
#define chain_val                  CHAIN_NB_VAL




/*---------------------------------*
 * Type Definitions                *
 *---------------------------------*/

/*---------------------------------*
 * Global Variables                *
 *---------------------------------*/

/*---------------------------------*
 * Function Prototypes             *
 *---------------------------------*/




/*---------------------------------*
 * Auxiliary engine macros         *
 *---------------------------------*/

#define DivDn(x, y)                ((x) / (y))
#define DivUp(x, y)                (((x) + (y) - 1) / (y))


#define R(r_no)                    rr##r_no

	  /* Interface with Prolog clauses instructions */

#define fd_create_a_frame(nb_arg)		\
  AF = CS;					\
  CS += nb_arg;




#define fd_int_in_a_frame(arg, offset)			\
  AF[offset] = (WamWord) Pl_Fd_Prolog_To_Value(fd_##arg);




#define fd_range_in_a_frame(arg, offset)			\
  AF[offset] = (WamWord) Pl_Fd_Prolog_To_Range(fd_##arg);




#define fd_fdv_in_a_frame(arg, offset)				\
  AF[offset] = (WamWord) Pl_Fd_Prolog_To_Fd_Var(fd_##arg, TRUE);




#define fd_fdv_in_a_frame(arg, offset)				\
  AF[offset] = (WamWord) Pl_Fd_Prolog_To_Fd_Var(fd_##arg, TRUE);




#define fd_any_in_a_frame(arg, offset)		\
  AF[offset] = (WamWord) fd_##arg;




#define fd_l_int_in_a_frame(arg, offset)			\
  AF[offset] = (WamWord) Pl_Fd_Prolog_To_Array_Int(fd_##arg);




#define fd_l_range_in_a_frame(arg, offset)			\
  printf("fd_l_range_in_a_frame  not yet implemented...\n");




#define fd_l_fdv_in_a_frame(arg, offset)				\
  AF[offset] = (WamWord) Pl_Fd_Prolog_To_Array_Fdv(fd_##arg, TRUE);




#define fd_l_any_in_a_frame(arg, offset)			\
  AF[offset] = (WamWord) Pl_Fd_Prolog_To_Array_Any(fd_##arg);




#define fd_cf_in_a_frame(offset)		\
  AF[offset] = (WamWord) CF;




#define fd_call_internal(fct_name)			\
  if (!fct_name(AF))					\
    {							\
      ret_val = FALSE;					\
      goto lab_exit;					\
    }




#define fd_call_internal_and_test_switch_simple(fct_name)	\
{								\
  long (*fct) () = (long (*)()) fct_name(AF);			\
								\
  if (fct == (long (*)()) FALSE)				\
    {								\
      ret_val = FALSE;						\
      goto lab_exit;						\
    }								\
  if (fct != (long (*)()) TRUE)	/* FD switch case triggered */	\
    {								\
      if ((*fct) (AF) == FALSE)					\
	{							\
	  ret_val = FALSE;					\
	  goto lab_exit;					\
	}							\
    }								\
}




#define fd_call_internal_and_test_switch(fct_name)		\
{								\
  long (*fct) () = (long (*)()) fct_name(AF);			\
								\
  if (fct == (long (*)()) FALSE)				\
    {								\
      ret_val = FALSE;						\
      goto lab_exit;						\
    }								\
  if (fct != (long (*)()) TRUE)	/* FD switch case triggered */	\
    {								\
      if ((*fct) (AF) == FALSE)					\
	{							\
	  ret_val = FALSE;					\
	  goto lab_exit;					\
	}							\
								\
      Pl_Fd_Stop_Constraint(CF);					\
    }								\
}






#define fd_stop_constraint(offset)					  \
  if (AF[offset])                                                         \
    Pl_Fd_Stop_Constraint((WamWord *) (AF[offset]));




	  /* Install instructions */

#define fd_create_c_frame(fct_name, tell_fv, optim2)			   \
  CF = Pl_Fd_Create_C_Frame(fct_name, AF, 					   \
                         (tell_fv == -1) ? NULL : Frame_Variable(tell_fv), \
                         optim2);




#define fd_add_dependency(fv, ch)				\
  Pl_Fd_Add_Dependency(Frame_Variable(fv), chain_##ch, CF);




#define fd_add_list_dependency(fv, ch)				\
  Pl_Fd_Add_List_Dependency(Frame_Variable(fv), chain_##ch, CF);




	  /* Constraint instructions */

#define fd_before_add_constraint		\
  Pl_Fd_Before_Add_Cstr();




#define fd_after_add_constraint			\
  if (!Pl_Fd_After_Add_Cstr())			\
    {						\
      ret_val = FALSE;				\
      goto lab_exit;				\
    }



#define fd_allocate				\
{						\
  WamWord *save_CS = CS;			\
  CS += pl_vec_size;




#define fd_deallocate				\
  CS = save_CS;					\
}




#define fd_tell_value(fv, t)			\
{						\
  fdv_adr = Frame_Variable(fv);			\
  if (!Pl_Fd_Tell_Value(fdv_adr, t))		\
    {						\
      ret_val = FALSE;				\
      goto lab_exit;				\
    }						\
}




#define fd_tell_not_value(fv, t)		\
{						\
  fdv_adr = Frame_Variable(fv);			\
  if (!Pl_Fd_Tell_Not_Value(fdv_adr, t))		\
    {						\
      ret_val = FALSE;				\
      goto lab_exit;				\
    }						\
}




#define fd_tell_interval(fv, t_min, t_max)				\
{									\
  fdv_adr = Frame_Variable(fv);						\
  if (Fd_Variable_Is_Ground(fdv_adr))					\
    {									\
      int n = Min(fdv_adr);						\
									\
      if (n < (int) (t_min) || n > (int) (t_max))			\
	{ /* also detects if initial range is empty */			\
	  ret_val = FALSE;						\
	  goto lab_exit;						\
	}								\
    }									\
  else if (Is_Sparse(Range (fdv_adr)))					\
    {									\
      Range range;							\
									\
      Range_Init_Interval(&range, t_min, t_max);			\
									\
      if (!Pl_Fd_Tell_Range_Range(fdv_adr, &range))			\
	{								\
	  ret_val = FALSE;						\
	  goto lab_exit;						\
	}								\
    }									\
  else if (!Pl_Fd_Tell_Interv_Interv(fdv_adr, t_min, t_max))		\
    {									\
      ret_val = FALSE;							\
      goto lab_exit;							\
    }									\
}





#define fd_tell_range(fv, r)				\
{							\
  fdv_adr = Frame_Variable(fv);				\
  if (Fd_Variable_Is_Ground(fdv_adr))			\
    {							\
      if (!Pl_Fd_Tell_Int_Range(fdv_adr, &R(r)))		\
	{						\
	  ret_val = FALSE;				\
	  goto lab_exit;				\
	}						\
    }							\
  else if (!Pl_Fd_Tell_Range_Range(fdv_adr, &R(r)))	\
    {							\
      ret_val = FALSE;					\
      goto lab_exit;					\
    }							\
}




#define fd_check_fct(fct)			\
  if (!fct)					\
    {						\
      ret_val = FALSE;				\
      goto lab_exit;				\
    }


	  /* Tests */

#define fd_test_exit_condition(t)		\
  if (t)					\
    goto lab_exit;



#define fd_test_fail_condition(t)		\
  if (!t)					\
    {						\
      ret_val = FALSE;				\
      goto lab_exit;				\
    }





#define fd_test_switch_condition(t, fct_name)	\
  if (t)					\
    {						\
      ret_val = (long) fct_name;		\
      goto lab_exit;				\
    }




	  /* Range */

#define fd_range_interval(r, t_min, t_max)	\
  Range_Init_Interval(&R(r), t_min, t_max);




#define fd_load_range(r, fp)			\
  R(r).vec = NULL;				\
  Pl_Range_Copy(&R(r), Frame_Range_Parameter(fp));




#define fd_load_dom(r, fv)			\
  fdv_adr = Frame_Variable(fv);			\
  R(r).vec = NULL;				\
  Pl_Range_Copy(&R(r), Range(fdv_adr));




#define fd_range_union(r, r1)			\
  Pl_Range_Union(&R(r), &R(r1));




#define fd_range_inter(r, r1)			\
  Pl_Range_Inter(&R(r), &R(r1));




#define fd_range_compl(r)			\
  Pl_Range_Compl(&R(r));




#define fd_range_empty(r)			\
  R(r).vec = NULL;				\
  Set_To_Empty(&R(r));




#define fd_range_full(r)				\
  Range_Init_Interval(&R(r), 0, INTERVAL_MAX_INTEGER);




#define fd_range_set_value(r, t)		\
  Pl_Range_Set_Value(&R(r), t);




#define fd_range_reset_value(r, t)		\
  Pl_Range_Reset_Value(&R(r), t);




#define fd_range_add_range(r, r1)		\
  Pl_Range_Add_Range(&R(r), &R(r1));




#define fd_range_sub_range(r, r1)		\
  Pl_Range_Sub_Range(&R(r), &R(r1));




#define fd_range_mul_range(r, r1)		\
  Pl_Range_Mul_Range(&R(r), &R(r1));




#define fd_range_div_range(r, r1)		\
  Pl_Range_Div_Range(&R(r), &R(r1));




#define fd_range_mod_range(r, r1)		\
  Pl_Range_Mod_Range(&R(r), &R(r1));




#define fd_range_add_value(r, t)		\
  Pl_Range_Add_Value(&R(r), t);




#define fd_range_sub_value(r, t)		\
  Pl_Range_Add_Value(&R(r), -(t));




#define fd_range_mul_value(r, t)		\
  Pl_Range_Mul_Value(&R(r), t);




#define fd_range_div_value(r, t)		\
  Pl_Range_Div_Value(&R(r), t);




#define fd_range_mod_value(r, t)		\
  Pl_Range_Mod_Value(&R(r), t);




#define fd_range_copy(r, r1)			\
  R(r).vec = NULL;				\
  Pl_Range_Copy(&R(r), &R(r1));




#define fd_range_fct(fct_name, r, args)		\
{						\
  void fct_name();				\
  R(r).vec = NULL;				\
  fct_name(&R(r), args);			\
}



	  /* term */

#define fd_load_int(var_name, fp)		\
  var_name = Frame_Term_Parameter(fp);




#define fd_load_min(var_name, fv)		\
  fdv_adr = Frame_Variable(fv);			\
  var_name = Min(fdv_adr);




#define fd_load_max(var_name, fv)		\
  fdv_adr = Frame_Variable(fv);			\
  var_name = Max(fdv_adr);




#define fd_load_min_max(var_name_min, var_name_max, fv)	\
  fdv_adr = Frame_Variable(fv);				\
  var_name_min = Min(fdv_adr);				\
  var_name_max = Max(fdv_adr);




#define fd_load_val(var_name, fv)		\
  fdv_adr = Frame_Variable(fv);			\
  if (Fd_Variable_Is_Ground(fdv_adr))		\
      var_name = Min(fdv_adr);			\
   else						\
      goto lab_exit;




#define fd_min_of_range(var_name, r)		\
    var_name = R(r).min;




#define fd_max_of_range(var_name, r)		\
    var_name = R(r).max;




#define fd_value_copy(t, t1)			\
    (t) = (t1);




#define fd_load_l_int(var_name, fp)		\
  var_name = Frame_List_Parameter(fp);




#define fd_load_l_fdv(var_name, fp)		\
  var_name = Frame_List_Parameter(fp);




#define fd_load_l_any(var_name, fp)		\
  var_name = Frame_List_Parameter(fp);




#define arg_1(a1)                                 a1
#define arg_2(a1, a2)                             a1, a2
#define arg_3(a1, a2, a3)                         a1, a2, a3
#define arg_4(a1, a2, a3, a4)                     a1, a2, a3, a4
#define arg_5(a1, a2, a3, a4, a5)                 a1, a2, a3, a4, a5
#define arg_6(a1, a2, a3, a4, a5, a6)             a1, a2, a3, a4, a5, a6
#define arg_7(a1, a2, a3, a4, a5, a6, a7)         a1, a2, a3, a4, a5, a6, a7
#define arg_8(a1, a2, a3, a4, a5, a6, a7, a8)     a1, a2, a3, a4, a5, a6, a7, a8
#define arg_9(a1, a2, a3, a4, a5, a6, a7, a8, a9) a1, a2, a3, a4, a5, a6, a7, a8, a9




#define range_arg(r)              &R(r)	/* by address */




/*---------------------------------*
 * Interface with C files          *
 *---------------------------------*/

#define max_integer                INTERVAL_MAX_INTEGER




#define FdArg(arg)                 WamWord fd_##arg




#define fd_begin_user_constraint(name_args)	\
Bool						\
name_args					\
{						\
  WamWord *AF;					\
  long ret_val = TRUE;




#define fd_end_user_constraint			\
}




#define fd_begin_internal(fct_name)		\
static long					\
fct_name(WamWord *AF)				\
{						\
  long ret_val = TRUE;




#define fd_end_internal				\
}




#define fd_exit_point				\
  lab_exit:



#define fd_return				\
  return ret_val;




#define fd_local_value_var(var_name)		\
  int var_name;




#define fd_local_range_var(r)			\
  Range R(r);    /*  = {FALSE, 0, 0, NULL} init should be useless  */




#define fd_local_l_int_var(var_name)		\
  WamWord *var_name;




#define fd_local_l_fdv_var(var_name)		\
  WamWord *var_name;




#define fd_local_l_any_var(var_name)		\
  WamWord *var_name;




#define fd_local_cf_pointer			\
  WamWord *CF;


#ifdef __GNUC__
#define fd_local_fdv_adr			\
  WamWord *fdv_adr __attribute__((unused));
#else
#define fd_local_fdv_adr			\
  WamWord *fdv_adr;
#endif



#define fd_init_local_value_var(var_name, term)	\
  var_name = (term);




#define fd_forall(fv, l_fv)	\
{				\
  int n = *l_fv++;		\
  while (n--)			\
    {				\
       AF[fv] = *l_fv++;




#define fd_forall_end      	\
    }				\
}


#endif /* !_FD_TO_C_H */
