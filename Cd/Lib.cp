(**
 * CD - Canvas Draw
 * Tecgraf: Computer Graphics Technology Group, PUC-Rio, Brazil
 * http://www.tecgraf.puc-rio.br/cd  mailto:cd@tecgraf.puc-rio.br
 *)
MODULE CdLib ["cd"];

CONST
    NAME* = "CD - Canvas Draw";
    COPYRIGHT* = "Copyright (C) 1994-2013 Tecgraf, PUC-Rio.";
    DESCRIPTION* = "A 2D Graphics Library";
    VERSION* = "5.6";
    VERSION_NUMBER* = 506000;
    VERSION_DATE* = "2012/11/28";

    (* query value *)
    QUERY* = -1;

    (* bitmap type *)
    (* these definitions are compatible with the IM library *)                        
    RGB*  = 0;                      
    MAP*  = 1;
    RGBA* = 0100H;

    (* bitmap data *)
    IRED*   = 0;
    IGREEN* = 1;
    IBLUE*  = 2;
    IALPHA* = 3;
    INDEX*  = 4;
    COLORS* = 5;

    (* status report *)
    ERROR* = -1;
    OK*    =  0;

    (* clip mode *)
    CLIPOFF*     = 0;
    CLIPAREA*    = 1;
    CLIPPOLYGON* = 2;
    CLIPREGION*  = 3;


    (* region combine mode *)
    UNION*        = 0;
    INTERSECT*    = 1;
    DIFFERENCE*   = 2;
    NOTINTERSECT* = 3;

    (* polygon mode (begin...end) *)
    FILL*         = 0;
    OPEN_LINES*   = 1;
    CLOSED_LINES* = 2;
    CLIP*         = 3;
    BEZIER*       = 4;
    REGION*       = 5;
    PATH*         = 6;

    POLYCUSTOM* = 10;

    (* path actions *)
    PATH_NEW*        = 0;
    PATH_MOVETO*     = 1;
    PATH_LINETO*     = 2;
    PATH_ARC*        = 3;
    PATH_CURVETO*    = 4;
    PATH_CLOSE*      = 5;
    PATH_FILL*       = 6;
    PATH_STROKE*     = 7;
    PATH_FILLSTROKE* = 8;
    PATH_CLIP*       = 9;

    (* fill mode *)
    EVENODD* = 0;
    WINDING* = 1;

    (* line join  *)
    MITER* = 0;
    BEVEL* = 1;
    ROUND* = 2;

    (* line cap  *)
    CAPFLAT*   = 0;  
    CAPSQUARE* = 0;
    CAPROUND*  = 0;

    (* background opacity mode *)
    OPAQUE*      = 0;
    TRANSPARENT* = 1;

    (* write mode *)
    REPLACE* = 0;
    XOR*     = 1;
    NOT_XOR* = 2;

    (* color allocation mode (palette) *)
    POLITE* = 0;
    FORCE*  = 1;

    (* line style *)
    CONTINUOUS*   = 0;
    DASHED*       = 1;
    DOTTED*       = 2;
    DASH_DOT*     = 3;
    DASH_DOT_DOT* = 4;
    CUSTOM*       = 5;

    (* marker type *)
    PLUS*           = 0;
    STAR*           = 1;
    CIRCLE*         = 2;
    X*              = 3;
    BOX*            = 4;
    DIAMOND*        = 5;
    HOLLOW_CIRCLE*  = 6;
    HOLLOW_BOX*     = 7;
    HOLLOW_DIAMOND* = 8;

    (* hatch type *)
    HORIZONTAL* = 0;
    VERTICAL*   = 1;
    FDIAGONAL*  = 2;
    BDIAGONAL*  = 3;
    CROSS*      = 4;
    DIAGCROSS*  = 5;

    (* interior style *)
    SOLID*   = 0;
    HATCH*   = 1;
    STIPPLE* = 2;
    PATTERN* = 3;
    HOLLOW*  = 4;

    (* text alignment *)
    NORTH*       =  0;
    SOUTH*       =  1;
    EAST*        =  2;
    WEST*        =  3;
    NORTH_EAST*  =  4;
    NORTH_WEST*  =  5;
    SOUTH_EAST*  =  6;
    SOUTH_WEST*  =  7;
    CENTER*      =  8;
    BASE_LEFT*   =  9;
    BASE_CENTER* = 10;
    BASE_RIGHT*  = 11;

    (* style *)
    PLAIN*     = { }; (* 0 *)
    BOLD*      = {0}; (* 1 *)
    ITALIC*    = {1}; (* 2 *)
    UNDERLINE* = {3}; (* 4 *)
    STRIKEOUT* = {7}; (* 8 *)

    (* some font sizes *)
    SMALL*    =  8;
    STANDARD* = 12;
    LARGE*    = 18;

    (* Context Capabilities *)
    CAP_NONE*            = 000000000H;
    CAP_FLUSH*           = 000000001H;
    CAP_CLEAR*           = 000000002H;
    CAP_PLAY*            = 000000004H;
    CAP_YAXIS*           = 000000008H;
    CAP_CLIPAREA*        = 000000010H;
    CAP_CLIPPOLY*        = 000000020H;
    CAP_REGION*          = 000000040H;
    CAP_RECT*            = 000000080H;
    CAP_CHORD*           = 000000100H;
    CAP_IMAGERGB*        = 000000200H;
    CAP_IMAGERGBA*       = 000000400H;
    CAP_IMAGEMAP*        = 000000800H;
    CAP_GETIMAGERGB*     = 000001000H;
    CAP_IMAGESRV*        = 000002000H;
    CAP_BACKGROUND*      = 000004000H;
    CAP_BACKOPACITY*     = 000008000H;
    CAP_WRITEMODE*       = 000010000H;
    CAP_LINESTYLE*       = 000020000H;
    CAP_LINEWITH*        = 000040000H;
    CAP_FPRIMTIVES*      = 000080000H;
    CAP_HATCH*           = 000100000H;
    CAP_STIPPLE*         = 000200000H;
    CAP_PATTERN*         = 000400000H;
    CAP_FONT*            = 000800000H;
    CAP_FONTDIM*         = 001000000H;
    CAP_TEXTSIZE*        = 002000000H;
    CAP_TEXTORIENTATION* = 004000000H;
    CAP_PALETTE*         = 008000000H;
    CAP_LINECAP*         = 010000000H;
    CAP_LINEJOIN*        = 020000000H;
    CAP_PATH*            = 040000000H;
    CAP_BEZIER*          = 080000000H;
    CAP_ALL*             = 0FFFFFFFFH;

    (* Context Types *)
    CTX_WINDOW* = 0; 
    CTX_DEVICE* = 1; 
    CTX_IMAGE*  = 2;
    CTX_FILE*   = 3;

    (* cdPlay definitions *)
    SIZECB*   = 0; (* size callback *)
    ABORT*    = 1;
    CONTINUE* = 0;

    (* simulation flags *)
    SIM_NONE*     = 00000H;
    SIM_LINE*     = 00001H;
    SIM_RECT*     = 00002H;
    SIM_BOX*      = 00004H;
    SIM_ARC*      = 00008H;
    SIM_SECTOR*   = 00010H;
    SIM_CHORD*    = 00020H;
    SIM_POLYLINE* = 00040H;
    SIM_POLYGON*  = 00080H;
    SIM_TEXT*     = 00100H;
    SIM_ALL*      = 0FFFFH;

    (*
    SIM_LINES* = (CD_SIM_LINE | CD_SIM_RECT | CD_SIM_ARC | CD_SIM_POLYLINE);
    SIM_FILLS* = (CD_SIM_BOX | CD_SIM_SECTOR | CD_SIM_CHORD | CD_SIM_POLYGON);
    *)

    (* some predefined colors for convenience *)
    RED*          = 0FF0000H;   (* 255,  0,  0 *)
    DARK_RED*     = 0800000H;   (* 128,  0,  0 *)
    GREEN*        = 000FF00H;   (*   0,255,  0 *)
    DARK_GREEN*   = 0008000H;   (*   0,128,  0 *)
    BLUE*         = 00000FFH;   (*   0,  0,255 *)
    DARK_BLUE*    = 0000080H;   (*   0,  0,128 *)
    YELLOW*       = 0FFFF00H;   (* 255,255,  0 *)
    DARK_YELLOW*  = 0808000H;   (* 128,128,  0 *)
    MAGENTA*      = 0FF00FFH;   (* 255,  0,255 *)
    DARK_MAGENTA* = 0800080H;   (* 128,  0,128 *)
    CYAN*         = 000FFFFH;   (*   0,255,255 *)
    DARK_CYAN*    = 0008080H;   (*   0,128,128 *)
    WHITE*        = 0FFFFFFH;   (* 255,255,255 *)
    BLACK*        = 0000000H;   (*   0,  0,  0 *)
    DARK_GRAY*    = 0808080H;   (* 128,128,128 *)
    GRAY*         = 0C0C0C0H;   (* 192,192,192 *)

    (* some usefull conversion factors *)
    MM2PT*   =   2.834645669;  (* milimeters to points (pt = CD_MM2PT * mm) *)
    RAD2DEG* =  57.295779513;  (* radians to degrees (deg = CD_RAD2DEG * rad) *)
    DEG2RAD* = 0.01745329252;  (* degrees to radians (rad = CD_DEG2RAD * deg) *)

    (* paper sizes *)
    A0* = 0;
    A1* = 1;
    A2* = 2;
    A3* = 3;
    A4* = 4;
    A5* = 5;
    LETTER* = 6;
    LEGAL* = 7;

TYPE
    Context*  = POINTER TO LIMITED RECORD [untagged] END;
    Canvas*   = POINTER TO LIMITED RECORD [untagged] END;
    State*    = POINTER TO LIMITED RECORD [untagged] END;
    Image*    = POINTER TO LIMITED RECORD [untagged] END;
    String*   = POINTER TO ARRAY [untagged] OF SHORTCHAR;
    Callback* = INTEGER;
    Pointer*  = POINTER TO LIMITED RECORD [untagged] END;
    Bitmap*   = POINTER TO LIMITED RECORD
      w, h, type: INTEGER;
      data: Pointer
    END;
    SizeCB*   = PROCEDURE [ccall] (canvas: Canvas; w, h: INTEGER; w_mm, h_mm: REAL): INTEGER;

(*  library  *)
(* char*         cdVersion(void); *)
PROCEDURE [ccall] Version* ["cdVersion"] (): String;
(* char*         cdVersionDate(void); *)
PROCEDURE [ccall] VersionDate* ["cdVersionDate"] (): String;
(* int           cdVersionNumber(void); *)
PROCEDURE [ccall] VersionNumber* ["cdVersionNumber"] (): INTEGER;
(*  canvas init  *)
(* cdCanvas*   cdCreateCanvas(cdContext *context, void *data); *)
PROCEDURE [ccall] CreateCanvas* ["cdCreateCanvas"] (context: Context; data: Pointer): Canvas;
(* cdCanvas*   cdCreateCanvasf(cdContext *context, const char* format, ...); *)
(*
PROCEDURE [ccall] CreateCanvasf* ["cdCreateCanvasf"] (context: Context; format: String; ...): Canvas;*)
(* void        cdKillCanvas(cdCanvas* canvas); *)
PROCEDURE [ccall] KillCanvas* ["cdKillCanvas"] (canvas: Canvas);
(* cdContext*  cdCanvasGetContext(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasGetContext* ["cdCanvasGetContext"] (canvas: Canvas): Context;
(* int         cdCanvasActivate(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasActivate* ["cdCanvasActivate"] (canvas: Canvas): INTEGER;
(* void        cdCanvasDeactivate(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasDeactivate* ["cdCanvasDeactivate"] (canvas: Canvas);
(* int         cdUseContextPlus(int use); *)
PROCEDURE [ccall] UseContextPlus* ["cdUseContextPlus"] (use: INTEGER): INTEGER;
(* void        cdInitContextPlus(void);    need an external library  *)
PROCEDURE [ccall] InitContextPlus* ["cdInitContextPlus"] ();
(* void        cdFinishContextPlus(void);    need an external library  *)
PROCEDURE [ccall] FinishContextPlus* ["cdFinishContextPlus"] ();
(*  context  *)
(* typedef int (cdCallback)(cdCanvas* canvas); *)
(*PROCEDURE [ccall] Callback* ["cdCallback"] (canvas: Canvas): ;*)
(* int cdContextRegisterCallback(cdContext *context, int cb, cdCallback func); *)
PROCEDURE [ccall] ContextRegisterCallback* ["cdContextRegisterCallback"] (context: Context; cb: INTEGER; func: Callback): INTEGER;
(* unsigned long cdContextCaps(cdContext *context); *)
PROCEDURE [ccall] ContextCaps* ["cdContextCaps"] (context: Context): INTEGER;
(* int cdContextIsPlus(cdContext *context); *)
PROCEDURE [ccall] ContextIsPlus* ["cdContextIsPlus"] (context: Context): INTEGER;
(* int cdContextType(cdContext *context); *)
PROCEDURE [ccall] ContextType* ["cdContextType"] (context: Context): INTEGER;
(*  control  *)
(* int      cdCanvasSimulate(cdCanvas* canvas, int mode); *)
PROCEDURE [ccall] CanvasSimulate* ["cdCanvasSimulate"] (canvas: Canvas; mode: INTEGER): INTEGER;
(* void     cdCanvasFlush(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasFlush* ["cdCanvasFlush"] (canvas: Canvas);
(* void     cdCanvasClear(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasClear* ["cdCanvasClear"] (canvas: Canvas);
(* cdState* cdCanvasSaveState(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasSaveState* ["cdCanvasSaveState"] (canvas: Canvas): State;
(* void     cdCanvasRestoreState(cdCanvas* canvas, cdState* state); *)
PROCEDURE [ccall] CanvasRestoreState* ["cdCanvasRestoreState"] (canvas: Canvas; state: State);
(* void     cdReleaseState(cdState* state); *)
PROCEDURE [ccall] ReleaseState* ["cdReleaseState"] (state: State);
(* void     cdCanvasSetAttribute(cdCanvas* canvas, const char* name, char* data); *)
PROCEDURE [ccall] CanvasSetAttribute* ["cdCanvasSetAttribute"] (canvas: Canvas; name: String; data: String);
(* void     cdCanvasSetfAttribute(cdCanvas* canvas, const char* name, const char* format); *)
PROCEDURE [ccall] CanvasSetfAttribute* ["cdCanvasSetfAttribute"] (canvas: Canvas; name, format: String);
(* char*    cdCanvasGetAttribute(cdCanvas* canvas, const char* name); *)
PROCEDURE [ccall] CanvasGetAttribute* ["cdCanvasGetAttribute"] (canvas: Canvas; name: String): String;
(*  interpretation  *)
(* int  cdCanvasPlay(cdCanvas* canvas, cdContext *context, int xmin, int xmax, int ymin, int ymax, void *data); *)
PROCEDURE [ccall] CanvasPlay* ["cdCanvasPlay"] (canvas: Canvas; context: Context; xmin, xmax, ymin, ymax: INTEGER; data: Pointer): INTEGER;
(*  coordinate transformation  *)
(* void cdCanvasGetSize(cdCanvas* canvas, int *width, int *height, double *width_mm, double *height_mm); *)
PROCEDURE [ccall] CanvasGetSize* ["cdCanvasGetSize"] (canvas: Canvas; VAR width, height: INTEGER; VAR width_mm, height_mm: REAL);
(* int cdCanvasUpdateYAxis(cdCanvas* canvas, int* y); *)
PROCEDURE [ccall] CanvasUpdateYAxis* ["cdCanvasUpdateYAxis"] (canvas: Canvas; VAR y: INTEGER): INTEGER;
(* double cdfCanvasUpdateYAxis(cdCanvas* canvas, double* y); *)
PROCEDURE [ccall] fCanvasUpdateYAxis* ["cdfCanvasUpdateYAxis"] (canvas: Canvas; VAR y: REAL): REAL;
(* int cdCanvasInvertYAxis(cdCanvas* canvas, int y); *)
PROCEDURE [ccall] CanvasInvertYAxis* ["cdCanvasInvertYAxis"] (canvas: Canvas; y: INTEGER): INTEGER;
(* double cdfCanvasInvertYAxis(cdCanvas* canvas, double y); *)
PROCEDURE [ccall] fCanvasInvertYAxis* ["cdfCanvasInvertYAxis"] (canvas: Canvas; y: REAL): REAL;
(* void cdCanvasMM2Pixel(cdCanvas* canvas, double mm_dx, double mm_dy, int *dx, int *dy); *)
PROCEDURE [ccall] CanvasMM2Pixel* ["cdCanvasMM2Pixel"] (canvas: Canvas; mm_dx, mm_dy: REAL; VAR dx, dy: INTEGER);
(* void cdCanvasPixel2MM(cdCanvas* canvas, int dx, int dy, double *mm_dx, double *mm_dy); *)
PROCEDURE [ccall] CanvasPixel2MM* ["cdCanvasPixel2MM"] (canvas: Canvas; dx, dy: INTEGER; VAR mm_dx, mm_dy: REAL);
(* void cdfCanvasMM2Pixel(cdCanvas* canvas, double mm_dx, double mm_dy, double *dx, double *dy); *)
PROCEDURE [ccall] fCanvasMM2Pixel* ["cdfCanvasMM2Pixel"] (canvas: Canvas; mm_dx, mm_dy: REAL; VAR dx, dy: REAL);
(* void cdfCanvasPixel2MM(cdCanvas* canvas, double dx, double dy, double *mm_dx, double *mm_dy); *)
PROCEDURE [ccall] fCanvasPixel2MM* ["cdfCanvasPixel2MM"] (canvas: Canvas; dx, dy: REAL; VAR mm_dx, mm_dy: REAL);
(* void cdCanvasOrigin(cdCanvas* canvas, int x, int y); *)
PROCEDURE [ccall] CanvasOrigin* ["cdCanvasOrigin"] (canvas: Canvas; x, y: INTEGER);
(* void cdfCanvasOrigin(cdCanvas* canvas, double x, double y); *)
PROCEDURE [ccall] fCanvasOrigin* ["cdfCanvasOrigin"] (canvas: Canvas; x, y: REAL);
(* void cdCanvasGetOrigin(cdCanvas* canvas, int *x, int *y); *)
PROCEDURE [ccall] CanvasGetOrigin* ["cdCanvasGetOrigin"] (canvas: Canvas; VAR x, y: INTEGER);
(* void cdfCanvasGetOrigin(cdCanvas* canvas, double *x, double *y); *)
PROCEDURE [ccall] fCanvasGetOrigin* ["cdfCanvasGetOrigin"] (canvas: Canvas; VAR x, y: REAL);
(* void cdCanvasTransform(cdCanvas* canvas, const double* matrix); *)
PROCEDURE [ccall] CanvasTransform* ["cdCanvasTransform"] (canvas: Canvas; matrix: REAL);
(* double* cdCanvasGetTransform(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasGetTransform* ["cdCanvasGetTransform"] (canvas: Canvas): REAL;
(* void cdCanvasTransformMultiply(cdCanvas* canvas, const double* matrix); *)
PROCEDURE [ccall] CanvasTransformMultiply* ["cdCanvasTransformMultiply"] (canvas: Canvas; matrix: REAL);
(* void cdCanvasTransformRotate(cdCanvas* canvas, double angle); *)
PROCEDURE [ccall] CanvasTransformRotate* ["cdCanvasTransformRotate"] (canvas: Canvas; angle: REAL);
(* void cdCanvasTransformScale(cdCanvas* canvas, double sx, double sy); *)
PROCEDURE [ccall] CanvasTransformScale* ["cdCanvasTransformScale"] (canvas: Canvas; sx, sy: REAL);
(* void cdCanvasTransformTranslate(cdCanvas* canvas, double dx, double dy); *)
PROCEDURE [ccall] CanvasTransformTranslate* ["cdCanvasTransformTranslate"] (canvas: Canvas; dx, dy: REAL);
(* void cdCanvasTransformPoint(cdCanvas* canvas, int x, int y, int *tx, int *ty); *)
PROCEDURE [ccall] CanvasTransformPoint* ["cdCanvasTransformPoint"] (canvas: Canvas; x, y: INTEGER; VAR tx, ty: INTEGER);
(* void cdfCanvasTransformPoint(cdCanvas* canvas, double x, double y, double *tx, double *ty); *)
PROCEDURE [ccall] fCanvasTransformPoint* ["cdfCanvasTransformPoint"] (canvas: Canvas; x, y: REAL; VAR tx, ty: REAL);
(*  clipping  *)
(* int  cdCanvasClip(cdCanvas* canvas, int mode); *)
PROCEDURE [ccall] CanvasClip* ["cdCanvasClip"] (canvas: Canvas; mode: INTEGER): INTEGER;
(* void cdCanvasClipArea(cdCanvas* canvas, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] CanvasClipArea* ["cdCanvasClipArea"] (canvas: Canvas; xmin, xmax, ymin, ymax: INTEGER);
(* int  cdCanvasGetClipArea(cdCanvas* canvas, int *xmin, int *xmax, int *ymin, int *ymax); *)
PROCEDURE [ccall] CanvasGetClipArea* ["cdCanvasGetClipArea"] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: INTEGER): INTEGER;
(* void cdfCanvasClipArea(cdCanvas* canvas, double xmin, double xmax, double ymin, double ymax); *)
PROCEDURE [ccall] fCanvasClipArea* ["cdfCanvasClipArea"] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
(* int  cdfCanvasGetClipArea(cdCanvas* canvas, double *xmin, double *xmax, double *ymin, double *ymax); *)
PROCEDURE [ccall] fCanvasGetClipArea* ["cdfCanvasGetClipArea"] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: REAL): INTEGER;
(*  clipping region  *)
(* int  cdCanvasIsPointInRegion(cdCanvas* canvas, int x, int y); *)
PROCEDURE [ccall] CanvasIsPointInRegion* ["cdCanvasIsPointInRegion"] (canvas: Canvas; x, y: INTEGER): INTEGER;
(* void cdCanvasOffsetRegion(cdCanvas* canvas, int x, int y); *)
PROCEDURE [ccall] CanvasOffsetRegion* ["cdCanvasOffsetRegion"] (canvas: Canvas; x, y: INTEGER);
(* void cdCanvasGetRegionBox(cdCanvas* canvas, int *xmin, int *xmax, int *ymin, int *ymax); *)
PROCEDURE [ccall] CanvasGetRegionBox* ["cdCanvasGetRegionBox"] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: INTEGER);
(* int  cdCanvasRegionCombineMode(cdCanvas* canvas, int mode); *)
PROCEDURE [ccall] CanvasRegionCombineMode* ["cdCanvasRegionCombineMode"] (canvas: Canvas; mode: INTEGER): INTEGER;
(*  primitives  *)
(* void cdCanvasPixel(cdCanvas* canvas, int x, int y, long color); *)
PROCEDURE [ccall] CanvasPixel* ["cdCanvasPixel"] (canvas: Canvas; x, y: INTEGER; color: INTEGER);
(* void cdCanvasMark(cdCanvas* canvas, int x, int y); *)
PROCEDURE [ccall] CanvasMark* ["cdCanvasMark"] (canvas: Canvas; x, y: INTEGER);
(* void cdCanvasBegin(cdCanvas* canvas, int mode); *)
PROCEDURE [ccall] CanvasBegin* ["cdCanvasBegin"] (canvas: Canvas; mode: INTEGER);
(* void cdCanvasPathSet(cdCanvas* canvas, int action); *)
PROCEDURE [ccall] CanvasPathSet* ["cdCanvasPathSet"] (canvas: Canvas; action: INTEGER);
(* void cdCanvasEnd(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasEnd* ["cdCanvasEnd"] (canvas: Canvas);
(* void cdCanvasLine(cdCanvas* canvas, int x1, int y1, int x2, int y2); *)
PROCEDURE [ccall] CanvasLine* ["cdCanvasLine"] (canvas: Canvas; x1, y1, x2, y2: INTEGER);
(* void cdCanvasVertex(cdCanvas* canvas, int x, int y); *)
PROCEDURE [ccall] CanvasVertex* ["cdCanvasVertex"] (canvas: Canvas; x, y: INTEGER);
(* void cdCanvasRect(cdCanvas* canvas, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] CanvasRect* ["cdCanvasRect"] (canvas: Canvas; xmin, xmax, ymin, ymax: INTEGER);
(* void cdCanvasBox(cdCanvas* canvas, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] CanvasBox* ["cdCanvasBox"] (canvas: Canvas; xmin, xmax, ymin, ymax: INTEGER);
(* void cdCanvasArc(cdCanvas* canvas, int xc, int yc, int w, int h, double angle1, double angle2); *)
PROCEDURE [ccall] CanvasArc* ["cdCanvasArc"] (canvas: Canvas; xc, yc, w, h: INTEGER; angle1, angle2: REAL);
(* void cdCanvasSector(cdCanvas* canvas, int xc, int yc, int w, int h, double angle1, double angle2); *)
PROCEDURE [ccall] CanvasSector* ["cdCanvasSector"] (canvas: Canvas; xc, yc, w, h: INTEGER; angle1, angle2: REAL);
(* void cdCanvasChord(cdCanvas* canvas, int xc, int yc, int w, int h, double angle1, double angle2); *)
PROCEDURE [ccall] CanvasChord* ["cdCanvasChord"] (canvas: Canvas; xc, yc, w, h: INTEGER; angle1, angle2: REAL);
(* void cdCanvasText(cdCanvas* canvas, int x, int y, const char* s); *)
PROCEDURE [ccall] CanvasText* ["cdCanvasText"] (canvas: Canvas; x, y: INTEGER; s: String);
(* void cdfCanvasLine(cdCanvas* canvas, double x1, double y1, double x2, double y2); *)
PROCEDURE [ccall] fCanvasLine* ["cdfCanvasLine"] (canvas: Canvas; x1, y1, x2, y2: REAL);
(* void cdfCanvasVertex(cdCanvas* canvas, double x, double y); *)
PROCEDURE [ccall] fCanvasVertex* ["cdfCanvasVertex"] (canvas: Canvas; x, y: REAL);
(* void cdfCanvasRect(cdCanvas* canvas, double xmin, double xmax, double ymin, double ymax); *)
PROCEDURE [ccall] fCanvasRect* ["cdfCanvasRect"] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
(* void cdfCanvasBox(cdCanvas* canvas, double xmin, double xmax, double ymin, double ymax); *)
PROCEDURE [ccall] fCanvasBox* ["cdfCanvasBox"] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
(* void cdfCanvasArc(cdCanvas* canvas, double xc, double yc, double w, double h, double angle1, double angle2); *)
PROCEDURE [ccall] fCanvasArc* ["cdfCanvasArc"] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
(* void cdfCanvasSector(cdCanvas* canvas, double xc, double yc, double w, double h, double angle1, double angle2); *)
PROCEDURE [ccall] fCanvasSector* ["cdfCanvasSector"] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
(* void cdfCanvasChord(cdCanvas* canvas, double xc, double yc, double w, double h, double angle1, double angle2); *)
PROCEDURE [ccall] fCanvasChord* ["cdfCanvasChord"] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
(* void cdfCanvasText(cdCanvas* canvas, double x, double y, const char* s); *)
PROCEDURE [ccall] fCanvasText* ["cdfCanvasText"] (canvas: Canvas; x, y: REAL; s: String);
(*  attributes  *)
(* void cdCanvasSetBackground(cdCanvas* canvas, long color); *)
PROCEDURE [ccall] CanvasSetBackground* ["cdCanvasSetBackground"] (canvas: Canvas; color: INTEGER);
(* void cdCanvasSetForeground(cdCanvas* canvas, long color); *)
PROCEDURE [ccall] CanvasSetForeground* ["cdCanvasSetForeground"] (canvas: Canvas; color: INTEGER);
(* long cdCanvasBackground(cdCanvas* canvas, long color); *)
PROCEDURE [ccall] CanvasBackground* ["cdCanvasBackground"] (canvas: Canvas; color: INTEGER): INTEGER;
(* long cdCanvasForeground(cdCanvas* canvas, long color); *)
PROCEDURE [ccall] CanvasForeground* ["cdCanvasForeground"] (canvas: Canvas; color: INTEGER): INTEGER;
(* int  cdCanvasBackOpacity(cdCanvas* canvas, int opacity); *)
PROCEDURE [ccall] CanvasBackOpacity* ["cdCanvasBackOpacity"] (canvas: Canvas; opacity: INTEGER): INTEGER;
(* int  cdCanvasWriteMode(cdCanvas* canvas, int mode); *)
PROCEDURE [ccall] CanvasWriteMode* ["cdCanvasWriteMode"] (canvas: Canvas; mode: INTEGER): INTEGER;
(* int  cdCanvasLineStyle(cdCanvas* canvas, int style); *)
PROCEDURE [ccall] CanvasLineStyle* ["cdCanvasLineStyle"] (canvas: Canvas; style: INTEGER): INTEGER;
(* void cdCanvasLineStyleDashes(cdCanvas* canvas, const int* dashes, int count); *)
PROCEDURE [ccall] CanvasLineStyleDashes* ["cdCanvasLineStyleDashes"] (canvas: Canvas; VAR dashes: INTEGER; count: INTEGER);
(* int  cdCanvasLineWidth(cdCanvas* canvas, int width); *)
PROCEDURE [ccall] CanvasLineWidth* ["cdCanvasLineWidth"] (canvas: Canvas; width: INTEGER): INTEGER;
(* int  cdCanvasLineJoin(cdCanvas* canvas, int join); *)
PROCEDURE [ccall] CanvasLineJoin* ["cdCanvasLineJoin"] (canvas: Canvas; join: INTEGER): INTEGER;
(* int  cdCanvasLineCap(cdCanvas* canvas, int cap); *)
PROCEDURE [ccall] CanvasLineCap* ["cdCanvasLineCap"] (canvas: Canvas; cap: INTEGER): INTEGER;
(* int  cdCanvasInteriorStyle(cdCanvas* canvas, int style); *)
PROCEDURE [ccall] CanvasInteriorStyle* ["cdCanvasInteriorStyle"] (canvas: Canvas; style: INTEGER): INTEGER;
(* int  cdCanvasHatch(cdCanvas* canvas, int style); *)
PROCEDURE [ccall] CanvasHatch* ["cdCanvasHatch"] (canvas: Canvas; style: INTEGER): INTEGER;
(* void cdCanvasStipple(cdCanvas* canvas, int w, int h, const unsigned char* stipple); *)
PROCEDURE [ccall] CanvasStipple* ["cdCanvasStipple"] (canvas: Canvas; w, h: INTEGER; stipple: String);
(* unsigned char* cdCanvasGetStipple(cdCanvas* canvas, int *n, int *m); *)
PROCEDURE [ccall] CanvasGetStipple* ["cdCanvasGetStipple"] (canvas: Canvas; VAR n, m: INTEGER): String;
(* void   cdCanvasPattern(cdCanvas* canvas, int w, int h, long const int *pattern); *)
PROCEDURE [ccall] CanvasPattern* ["cdCanvasPattern"] (canvas: Canvas; w, h: INTEGER; VAR pattern: INTEGER);
(* long*  cdCanvasGetPattern(cdCanvas* canvas, int* n, int* m); *)
PROCEDURE [ccall] CanvasGetPattern* ["cdCanvasGetPattern"] (canvas: Canvas; VAR n, m: INTEGER): INTEGER;
(* int    cdCanvasFillMode(cdCanvas* canvas, int mode); *)
PROCEDURE [ccall] CanvasFillMode* ["cdCanvasFillMode"] (canvas: Canvas; mode: INTEGER): INTEGER;
(* int    cdCanvasFont(cdCanvas* canvas, const char* type_face, int style, int size); *)
PROCEDURE [ccall] CanvasFont* ["cdCanvasFont"] (canvas: Canvas; type_face: String; style: SET; size: INTEGER): INTEGER;
(* void   cdCanvasGetFont(cdCanvas* canvas, char *type_face, int *style, int *size); *)
PROCEDURE [ccall] CanvasGetFont* ["cdCanvasGetFont"] (canvas: Canvas; type_face: String; VAR style, size: INTEGER);
(* char*  cdCanvasNativeFont(cdCanvas* canvas, const char* font); *)
PROCEDURE [ccall] CanvasNativeFont* ["cdCanvasNativeFont"] (canvas: Canvas; font: String): String;
(* int    cdCanvasTextAlignment(cdCanvas* canvas, int alignment); *)
PROCEDURE [ccall] CanvasTextAlignment* ["cdCanvasTextAlignment"] (canvas: Canvas; alignment: INTEGER): INTEGER;
(* double cdCanvasTextOrientation(cdCanvas* canvas, double angle); *)
PROCEDURE [ccall] CanvasTextOrientation* ["cdCanvasTextOrientation"] (canvas: Canvas; angle: REAL): REAL;
(* int    cdCanvasMarkType(cdCanvas* canvas, int type); *)
PROCEDURE [ccall] CanvasMarkType* ["cdCanvasMarkType"] (canvas: Canvas; type: INTEGER): INTEGER;
(* int    cdCanvasMarkSize(cdCanvas* canvas, int size); *)
PROCEDURE [ccall] CanvasMarkSize* ["cdCanvasMarkSize"] (canvas: Canvas; size: INTEGER): INTEGER;
(*  vector text  *)
(* void cdCanvasVectorText(cdCanvas* canvas, int x, int y, const char* s); *)
PROCEDURE [ccall] CanvasVectorText* ["cdCanvasVectorText"] (canvas: Canvas; x, y: INTEGER; s: String);
(* void cdCanvasMultiLineVectorText(cdCanvas* canvas, int x, int y, const char* s); *)
PROCEDURE [ccall] CanvasMultiLineVectorText* ["cdCanvasMultiLineVectorText"] (canvas: Canvas; x, y: INTEGER; s: String);
(*  vector text attributes  *)
(* char* cdCanvasVectorFont(cdCanvas* canvas, const char *filename); *)
PROCEDURE [ccall] CanvasVectorFont* ["cdCanvasVectorFont"] (canvas: Canvas; filename: String): String;
(* void  cdCanvasVectorTextDirection(cdCanvas* canvas, int x1, int y1, int x2, int y2); *)
PROCEDURE [ccall] CanvasVectorTextDirection* ["cdCanvasVectorTextDirection"] (canvas: Canvas; x1, y1, x2, y2: INTEGER);
(* double* cdCanvasVectorTextTransform(cdCanvas* canvas, const double* matrix); *)
PROCEDURE [ccall] CanvasVectorTextTransform* ["cdCanvasVectorTextTransform"] (canvas: Canvas; matrix: REAL): REAL;
(* void  cdCanvasVectorTextSize(cdCanvas* canvas, int size_x, int size_y, const char* s); *)
PROCEDURE [ccall] CanvasVectorTextSize* ["cdCanvasVectorTextSize"] (canvas: Canvas; size_x, size_y: INTEGER; s: String);
(* int   cdCanvasVectorCharSize(cdCanvas* canvas, int size); *)
PROCEDURE [ccall] CanvasVectorCharSize* ["cdCanvasVectorCharSize"] (canvas: Canvas; size: INTEGER): INTEGER;
(* void  cdCanvasVectorFontSize(cdCanvas* canvas, double size_x, double size_y); *)
PROCEDURE [ccall] CanvasVectorFontSize* ["cdCanvasVectorFontSize"] (canvas: Canvas; size_x, size_y: REAL);
(* void  cdCanvasGetVectorFontSize(cdCanvas* canvas, double *size_x, double *size_y); *)
PROCEDURE [ccall] CanvasGetVectorFontSize* ["cdCanvasGetVectorFontSize"] (canvas: Canvas; VAR size_x, size_y: REAL);
(*  vector text properties  *)
(* void cdCanvasGetVectorTextSize(cdCanvas* canvas, const char* s, int *x, int *y); *)
PROCEDURE [ccall] CanvasGetVectorTextSize* ["cdCanvasGetVectorTextSize"] (canvas: Canvas; s: String; VAR x, y: INTEGER);
(* void cdCanvasGetVectorTextBounds(cdCanvas* canvas, const char* s, int x, int y, int *rect); *)
PROCEDURE [ccall] CanvasGetVectorTextBounds* ["cdCanvasGetVectorTextBounds"] (canvas: Canvas; s: String; x, y: INTEGER; VAR rect: INTEGER);
(* void cdCanvasGetVectorTextBox(cdCanvas* canvas, int x, int y, const char *s, int *xmin, int *xmax, int *ymin, int *ymax); *)
PROCEDURE [ccall] CanvasGetVectorTextBox* ["cdCanvasGetVectorTextBox"] (canvas: Canvas; x, y: INTEGER; s: String; VAR xmin, xmax, ymin, ymax: INTEGER);
(* void cdfCanvasVectorTextDirection(cdCanvas* canvas, double x1, double y1, double x2, double y2); *)
PROCEDURE [ccall] fCanvasVectorTextDirection* ["cdfCanvasVectorTextDirection"] (canvas: Canvas; x1, y1, x2, y2: REAL);
(* void cdfCanvasVectorTextSize(cdCanvas* canvas, double size_x, double size_y, const char* s); *)
PROCEDURE [ccall] fCanvasVectorTextSize* ["cdfCanvasVectorTextSize"] (canvas: Canvas; size_x, size_y: REAL; s: String);
(* void cdfCanvasGetVectorTextSize(cdCanvas* canvas, const char* s, double *x, double *y); *)
PROCEDURE [ccall] fCanvasGetVectorTextSize* ["cdfCanvasGetVectorTextSize"] (canvas: Canvas; s: String; VAR x, y: REAL);
(* double cdfCanvasVectorCharSize(cdCanvas* canvas, double size); *)
PROCEDURE [ccall] fCanvasVectorCharSize* ["cdfCanvasVectorCharSize"] (canvas: Canvas; size: REAL): REAL;
(* void cdfCanvasVectorText(cdCanvas* canvas, double x, double y, const char* s); *)
PROCEDURE [ccall] fCanvasVectorText* ["cdfCanvasVectorText"] (canvas: Canvas; x, y: REAL; s: String);
(* void cdfCanvasMultiLineVectorText(cdCanvas* canvas, double x, double y, const char* s); *)
PROCEDURE [ccall] fCanvasMultiLineVectorText* ["cdfCanvasMultiLineVectorText"] (canvas: Canvas; x, y: REAL; s: String);
(* void cdfCanvasGetVectorTextBounds(cdCanvas* canvas, const char* s, double x, double y, double *rect); *)
PROCEDURE [ccall] fCanvasGetVectorTextBounds* ["cdfCanvasGetVectorTextBounds"] (canvas: Canvas; s: String; x, y: REAL; VAR rect: REAL);
(* void cdfCanvasGetVectorTextBox(cdCanvas* canvas, double x, double y, const char *s, double *xmin, double *xmax, double *ymin, double *ymax); *)
PROCEDURE [ccall] fCanvasGetVectorTextBox* ["cdfCanvasGetVectorTextBox"] (canvas: Canvas; x, y: REAL; s: String; VAR xmin, xmax, ymin, ymax: REAL);
(*  properties  *)
(* void cdCanvasGetFontDim(cdCanvas* canvas, int *max_width, int *height, int *ascent, int *descent); *)
PROCEDURE [ccall] CanvasGetFontDim* ["cdCanvasGetFontDim"] (canvas: Canvas; VAR max_width, height, ascent, descent: INTEGER);
(* void cdCanvasGetTextSize(cdCanvas* canvas, const char* s, int *width, int *height); *)
PROCEDURE [ccall] CanvasGetTextSize* ["cdCanvasGetTextSize"] (canvas: Canvas; s: String; VAR width, height: INTEGER);
(* void cdCanvasGetTextBox(cdCanvas* canvas, int x, int y, const char* s, int *xmin, int *xmax, int *ymin, int *ymax); *)
PROCEDURE [ccall] CanvasGetTextBox* ["cdCanvasGetTextBox"] (canvas: Canvas; x, y: INTEGER; s: String; VAR xmin, xmax, ymin, ymax: INTEGER);
(* void cdCanvasGetTextBounds(cdCanvas* canvas, int x, int y, const char* s, int *rect); *)
PROCEDURE [ccall] CanvasGetTextBounds* ["cdCanvasGetTextBounds"] (canvas: Canvas; x, y: INTEGER; s: String; VAR rect: INTEGER);
(* int  cdCanvasGetColorPlanes(cdCanvas* canvas); *)
PROCEDURE [ccall] CanvasGetColorPlanes* ["cdCanvasGetColorPlanes"] (canvas: Canvas): INTEGER;
(*  color  *)
(* void cdCanvasPalette(cdCanvas* canvas, int n, const long *palette, int mode); *)
PROCEDURE [ccall] CanvasPalette* ["cdCanvasPalette"] (canvas: Canvas; n: INTEGER; palette: INTEGER; mode: INTEGER);
(*  client images  *)
(* void cdCanvasGetImageRGB(cdCanvas* canvas, unsigned char* r, unsigned char* g, unsigned char* b, int x, int y, int w, int h); *)
PROCEDURE [ccall] CanvasGetImageRGB* ["cdCanvasGetImageRGB"] (canvas: Canvas; r, g, b: String; x, y, w, h: INTEGER);
(* void cdCanvasPutImageRectRGB(cdCanvas* canvas, int iw, int ih, const unsigned char* r, const unsigned char* g, const unsigned char* b, int x, int y, int w, int h, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] CanvasPutImageRectRGB* ["cdCanvasPutImageRectRGB"] (canvas: Canvas; iw, ih: INTEGER; r, g, b: String; x, y, w, h, xmin, xmax, ymin, ymax: INTEGER);
(* void cdCanvasPutImageRectRGBA(cdCanvas* canvas, int iw, int ih, const unsigned char* r, const unsigned char* g, const unsigned char* b, const unsigned char* a, int x, int y, int w, int h, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] CanvasPutImageRectRGBA* ["cdCanvasPutImageRectRGBA"] (canvas: Canvas; iw, ih: INTEGER; r, g, b, a: String; x, y, w, h, xmin, xmax, ymin, ymax: INTEGER);
(* void cdCanvasPutImageRectMap(cdCanvas* canvas, int iw, int ih, const unsigned char* index, const long* colors, int x, int y, int w, int h, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] CanvasPutImageRectMap* ["cdCanvasPutImageRectMap"] (canvas: Canvas; iw, ih: INTEGER; index: String; colors: INTEGER; x, y, w, h, xmin, xmax, ymin, ymax: INTEGER);
(*  server images  *)
(* cdImage* cdCanvasCreateImage(cdCanvas* canvas, int w, int h); *)
PROCEDURE [ccall] CanvasCreateImage* ["cdCanvasCreateImage"] (canvas: Canvas; w, h: INTEGER): Image;
(* void cdKillImage(cdImage* image); *)
PROCEDURE [ccall] KillImage* ["cdKillImage"] (image: Image);
(* void cdCanvasGetImage(cdCanvas* canvas, cdImage* image, int x, int y); *)
PROCEDURE [ccall] CanvasGetImage* ["cdCanvasGetImage"] (canvas: Canvas; image: Image; x, y: INTEGER);
(* void cdCanvasPutImageRect(cdCanvas* canvas, cdImage* image, int x, int y, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] CanvasPutImageRect* ["cdCanvasPutImageRect"] (canvas: Canvas; image: Image; x, y, xmin, xmax, ymin, ymax: INTEGER);
(* void cdCanvasScrollArea(cdCanvas* canvas, int xmin, int xmax, int ymin, int ymax, int dx, int dy); *)
PROCEDURE [ccall] CanvasScrollArea* ["cdCanvasScrollArea"] (canvas: Canvas; xmin, xmax, ymin, ymax, dx, dy: INTEGER);
(*  bitmap  *)
(* cdBitmap* cdCreateBitmap(int w, int h, int type); *)
PROCEDURE [ccall] CreateBitmap* ["cdCreateBitmap"] (w, h, type: INTEGER): Bitmap;
(* cdBitmap* cdInitBitmap(int w, int h, int type); *)
PROCEDURE [ccall] InitBitmap* ["cdInitBitmap"] (w, h, type: INTEGER): Bitmap;
(* void cdKillBitmap(cdBitmap* bitmap); *)
PROCEDURE [ccall] KillBitmap* ["cdKillBitmap"] (bitmap: Bitmap);
(* unsigned char* cdBitmapGetData(cdBitmap* bitmap, int dataptr); *)
PROCEDURE [ccall] BitmapGetData* ["cdBitmapGetData"] (bitmap: Bitmap; dataptr: INTEGER): String;
(* void cdBitmapSetRect(cdBitmap* bitmap, int xmin, int xmax, int ymin, int ymax); *)
PROCEDURE [ccall] BitmapSetRect* ["cdBitmapSetRect"] (bitmap: Bitmap; xmin, xmax, ymin, ymax: INTEGER);
(* void cdCanvasPutBitmap(cdCanvas* canvas, cdBitmap* bitmap, int x, int y, int w, int h); *)
PROCEDURE [ccall] CanvasPutBitmap* ["cdCanvasPutBitmap"] (canvas: Canvas; bitmap: Bitmap; x, y, w, h: INTEGER);
(* void cdCanvasGetBitmap(cdCanvas* canvas, cdBitmap* bitmap, int x, int y); *)
PROCEDURE [ccall] CanvasGetBitmap* ["cdCanvasGetBitmap"] (canvas: Canvas; bitmap: Bitmap; x, y: INTEGER);
(* void cdBitmapRGB2Map(cdBitmap* bitmap_rgb, cdBitmap* bitmap_map); *)
PROCEDURE [ccall] BitmapRGB2Map* ["cdBitmapRGB2Map"] (bitmap_rgb, bitmap_map: Bitmap);
(*  color  *)
(* long cdEncodeColor(unsigned char red, unsigned char green, unsigned char blue); *)
PROCEDURE [ccall] EncodeColor* ["cdEncodeColor"] (red, green, blue: SHORTCHAR): INTEGER;
(* void cdDecodeColor(long color, unsigned char* red, unsigned char* green, unsigned char* blue); *)
PROCEDURE [ccall] DecodeColor* ["cdDecodeColor"] (color: INTEGER; red, green, blue: String);
(* unsigned char cdDecodeAlpha(long color); *)
PROCEDURE [ccall] DecodeAlpha* ["cdDecodeAlpha"] (color: INTEGER): SHORTCHAR;
(* long cdEncodeAlpha(long color, unsigned char alpha); *)
PROCEDURE [ccall] EncodeAlpha* ["cdEncodeAlpha"] (color: INTEGER; alpha: SHORTCHAR): INTEGER;
(* client image color convertion *)
PROCEDURE [ccall] GB2Map* ["cdRGB2Map"] (width, height: INTEGER; red, green, blue: String; index: String; pal_size: INTEGER; VAR color: INTEGER);

(* Canvas Initialization *)

(* Window-Base Drivers*)
PROCEDURE [ccall] ContextNativeWindow* ["cdContextNativeWindow"] (): Context;
(* Device-Based Drivers *)
PROCEDURE [ccall] ContextClipboard*    ["cdContextClipboard"   ] (): Context;
PROCEDURE [ccall] ContextPrinter*      ["cdContextPrinter"     ] (): Context;
PROCEDURE [ccall] ContextPicture*      ["cdContextPicture"     ] (): Context;
(* Image-Based Drivers  *)
PROCEDURE [ccall] ContextImage*        ["cdContextImage"       ] (): Context;
PROCEDURE [ccall] ContextImageRGB*     ["cdContextImageRGB"    ] (): Context;
PROCEDURE [ccall] ContextDBuffer*      ["cdContextDBuffer"     ] (): Context;
PROCEDURE [ccall] ContextDBufferRGB*   ["cdContextDBufferRGB"  ] (): Context;
(* File-Based Drivers *)
PROCEDURE [ccall] ContextPS*           ["cdContextPS"          ] (): Context;
PROCEDURE [ccall] ContextSVG*          ["cdContextSVG"         ] (): Context;
PROCEDURE [ccall] ContextMetafile*     ["cdContextMetafile"    ] (): Context;
PROCEDURE [ccall] ContextDebug*        ["cdContextDebug"       ] (): Context;
PROCEDURE [ccall] ContextCGM*          ["cdContextCGM"         ] (): Context;
PROCEDURE [ccall] ContextDGN*          ["cdContextDGN"         ] (): Context;
PROCEDURE [ccall] ContextDXF*          ["cdContextDXF"         ] (): Context;
PROCEDURE [ccall] ContextEMF*          ["cdContextEMF"         ] (): Context;
PROCEDURE [ccall] ContextWMF*          ["cdContextWMF"         ] (): Context;

BEGIN
END CdLib.
