/* ----------------------------- MNI Header -----------------------------------
@NAME       : group.h
@DESCRIPTION: Header file for acr-nema group code
@METHOD     : 
@GLOBALS    : 
@CREATED    : November 10, 1993 (Peter Neelin)
@MODIFIED   : $Log: group.h,v $
@MODIFIED   : Revision 1.4  1993-11-26 18:48:04  neelin
@MODIFIED   : Added group and group list copy routines.
@MODIFIED   :
 * Revision 1.3  93/11/24  11:26:38  neelin
 * Added group list stuff (dump and input).
 * 
 * Revision 1.2  93/11/22  13:12:41  neelin
 * Changed to use new Acr_Element_Id stuff.
 * 
 * Revision 1.1  93/11/19  12:50:32  neelin
 * Initial revision
 * 
@COPYRIGHT  :
              Copyright 1993 Peter Neelin, McConnell Brain Imaging Centre, 
              Montreal Neurological Institute, McGill University.
              Permission to use, copy, modify, and distribute this
              software and its documentation for any purpose and without
              fee is hereby granted, provided that the above copyright
              notice appear in all copies.  The author and McGill University
              make no representations about the suitability of this
              software for any purpose.  It is provided "as is" without
              express or implied warranty.
---------------------------------------------------------------------------- */

/* Group type */
typedef struct Acr_Group {
   int group_id;
   int nelements;
   long total_length;
   long group_length_offset;
   Acr_Element list_head;
   Acr_Element list_tail;
   struct Acr_Group *next;
} *Acr_Group;

/* Group length element id */
#define ACR_EID_GRPLEN 0

/* Functions */
public Acr_Group acr_create_group(int group_id);
public void acr_delete_group(Acr_Group group);
public void acr_delete_group_list(Acr_Group group_list);
public Acr_Group acr_copy_group(Acr_Group group);
public Acr_Group acr_copy_group_list(Acr_Group group_list);
public void acr_group_add_element(Acr_Group group, Acr_Element element);
public void acr_set_group_next(Acr_Group group, Acr_Group next);
public int acr_get_group_group(Acr_Group group);
public Acr_Element acr_get_group_element_list(Acr_Group group);
public long acr_get_group_total_length(Acr_Group group);
public int acr_get_group_nelements(Acr_Group group);
public Acr_Group acr_get_group_next(Acr_Group group);
public Acr_Status acr_input_group(Acr_File *afp, Acr_Group *group);
public Acr_Status acr_output_group(Acr_File *afp, Acr_Group group);
public Acr_Status acr_input_group_list(Acr_File *afp, Acr_Group *group_list,
                                       int max_group_id);
public Acr_Element acr_find_group_element(Acr_Group group_list,
                                          Acr_Element_Id elid);
public void acr_dump_group_list(FILE *file_pointer, Acr_Group group_list);