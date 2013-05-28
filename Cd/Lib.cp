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

PROCEDURE [ccall] Version*       ["cdVersion"      ] (): String;
PROCEDURE [ccall] VersionDate*   ["cdVersionDate"  ] (): String;
PROCEDURE [ccall] VersionNumber* ["cdVersionNumber"] (): INTEGER;

(*  canvas init  *)

PROCEDURE [ccall] CreateCanvas*  ["cdCreateCanvas"] (context: Context; data: Pointer): Canvas;
(*
PROCEDURE [ccall] CreateCanvasf*     ["cdCreateCanvasf"    ] (context: Context; format: String; ...): Canvas;*)
PROCEDURE [ccall] KillCanvas*        ["cdKillCanvas"       ] (canvas: Canvas);
PROCEDURE [ccall] CanvasGetContext*  ["cdCanvasGetContext" ] (canvas: Canvas): Context;
PROCEDURE [ccall] CanvasActivate*    ["cdCanvasActivate"   ] (canvas: Canvas): INTEGER;
PROCEDURE [ccall] CanvasDeactivate*  ["cdCanvasDeactivate" ] (canvas: Canvas);
PROCEDURE [ccall] UseContextPlus*    ["cdUseContextPlus"   ] (use: INTEGER): INTEGER;
PROCEDURE [ccall] InitContextPlus*   ["cdInitContextPlus"  ] ();
PROCEDURE [ccall] FinishContextPlus* ["cdFinishContextPlus"] ();

(*  context  *)

PROCEDURE [ccall] ContextRegisterCallback* ["cdContextRegisterCallback"] (context: Context; cb: INTEGER; func: Callback): INTEGER;
PROCEDURE [ccall] ContextCaps*             ["cdContextCaps"            ] (context: Context): INTEGER;
PROCEDURE [ccall] ContextIsPlus*           ["cdContextIsPlus"          ] (context: Context): INTEGER;
PROCEDURE [ccall] ContextType*             ["cdContextType"            ] (context: Context): INTEGER;

(*  control  *)

PROCEDURE [ccall] CanvasSimulate*      ["cdCanvasSimulate"     ] (canvas: Canvas; mode: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasFlush*         ["cdCanvasFlush"        ] (canvas: Canvas);
PROCEDURE [ccall] CanvasClear*         ["cdCanvasClear"        ] (canvas: Canvas);
PROCEDURE [ccall] CanvasSaveState*     ["cdCanvasSaveState"    ] (canvas: Canvas): State;
PROCEDURE [ccall] CanvasRestoreState*  ["cdCanvasRestoreState" ] (canvas: Canvas; state: State);
PROCEDURE [ccall] ReleaseState*        ["cdReleaseState"       ] (state: State);
PROCEDURE [ccall] CanvasSetAttribute*  ["cdCanvasSetAttribute" ] (canvas: Canvas; name: String; data: String);
PROCEDURE [ccall] CanvasSetfAttribute* ["cdCanvasSetfAttribute"] (canvas: Canvas; name, format: String);
PROCEDURE [ccall] CanvasGetAttribute*  ["cdCanvasGetAttribute" ] (canvas: Canvas; name: String): String;

(*  interpretation  *)

PROCEDURE [ccall] CanvasPlay* ["cdCanvasPlay"] (canvas: Canvas; context: Context; xmin, xmax, ymin, ymax: INTEGER; data: Pointer): INTEGER;

(*  coordinate transformation  *)

PROCEDURE [ccall] CanvasGetSize*      ["cdCanvasGetSize"     ] (canvas: Canvas; VAR width, height: INTEGER; VAR width_mm, height_mm: REAL);
PROCEDURE [ccall] CanvasUpdateYAxis*  ["cdCanvasUpdateYAxis" ] (canvas: Canvas; VAR y: INTEGER): INTEGER;
PROCEDURE [ccall] fCanvasUpdateYAxis* ["cdfCanvasUpdateYAxis"] (canvas: Canvas; VAR y: REAL): REAL;
PROCEDURE [ccall] CanvasInvertYAxis*  ["cdCanvasInvertYAxis" ] (canvas: Canvas; y: INTEGER): INTEGER;
PROCEDURE [ccall] fCanvasInvertYAxis* ["cdfCanvasInvertYAxis"] (canvas: Canvas; y: REAL): REAL;
PROCEDURE [ccall] CanvasMM2Pixel*     ["cdCanvasMM2Pixel"    ] (canvas: Canvas; mm_dx, mm_dy: REAL; VAR dx, dy: INTEGER);
PROCEDURE [ccall] CanvasPixel2MM*     ["cdCanvasPixel2MM"    ] (canvas: Canvas; dx, dy: INTEGER; VAR mm_dx, mm_dy: REAL);
PROCEDURE [ccall] fCanvasMM2Pixel*    ["cdfCanvasMM2Pixel"   ] (canvas: Canvas; mm_dx, mm_dy: REAL; VAR dx, dy: REAL);
PROCEDURE [ccall] fCanvasPixel2MM*    ["cdfCanvasPixel2MM"   ] (canvas: Canvas; dx, dy: REAL; VAR mm_dx, mm_dy: REAL);
PROCEDURE [ccall] CanvasOrigin*       ["cdCanvasOrigin"      ] (canvas: Canvas; x, y: INTEGER);
PROCEDURE [ccall] fCanvasOrigin*      ["cdfCanvasOrigin"     ] (canvas: Canvas; x, y: REAL);
PROCEDURE [ccall] CanvasGetOrigin*    ["cdCanvasGetOrigin"   ] (canvas: Canvas; VAR x, y: INTEGER);
PROCEDURE [ccall] fCanvasGetOrigin*   ["cdfCanvasGetOrigin"  ] (canvas: Canvas; VAR x, y: REAL);
PROCEDURE [ccall] CanvasTransform*    ["cdCanvasTransform"   ] (canvas: Canvas; matrix: REAL);
PROCEDURE [ccall] CanvasGetTransform* ["cdCanvasGetTransform"] (canvas: Canvas): REAL;
PROCEDURE [ccall] CanvasTransformMultiply*  ["cdCanvasTransformMultiply" ] (canvas: Canvas; matrix: REAL);
PROCEDURE [ccall] CanvasTransformRotate*    ["cdCanvasTransformRotate"   ] (canvas: Canvas; angle: REAL);
PROCEDURE [ccall] CanvasTransformScale*     ["cdCanvasTransformScale"    ] (canvas: Canvas; sx, sy: REAL);
PROCEDURE [ccall] CanvasTransformTranslate* ["cdCanvasTransformTranslate"] (canvas: Canvas; dx, dy: REAL);
PROCEDURE [ccall] CanvasTransformPoint*     ["cdCanvasTransformPoint"    ] (canvas: Canvas; x, y: INTEGER; VAR tx, ty: INTEGER);
PROCEDURE [ccall] fCanvasTransformPoint*    ["cdfCanvasTransformPoint"   ] (canvas: Canvas; x, y: REAL; VAR tx, ty: REAL);

(*  clipping  *)

PROCEDURE [ccall] CanvasClip*         ["cdCanvasClip"        ] (canvas: Canvas; mode: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasClipArea*     ["cdCanvasClipArea"    ] (canvas: Canvas; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasGetClipArea*  ["cdCanvasGetClipArea" ] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: INTEGER): INTEGER;
PROCEDURE [ccall] fCanvasClipArea*    ["cdfCanvasClipArea"   ] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] fCanvasGetClipArea* ["cdfCanvasGetClipArea"] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: REAL): INTEGER;

(*  clipping region  *)

PROCEDURE [ccall] CanvasIsPointInRegion*   ["cdCanvasIsPointInRegion"  ] (canvas: Canvas; x, y: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasOffsetRegion*      ["cdCanvasOffsetRegion"     ] (canvas: Canvas; x, y: INTEGER);
PROCEDURE [ccall] CanvasGetRegionBox*      ["cdCanvasGetRegionBox"     ] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasRegionCombineMode* ["cdCanvasRegionCombineMode"] (canvas: Canvas; mode: INTEGER): INTEGER;

(*  primitives  *)

PROCEDURE [ccall] CanvasPixel*   ["cdCanvasPixel"  ] (canvas: Canvas; x, y: INTEGER; color: INTEGER);
PROCEDURE [ccall] CanvasMark*    ["cdCanvasMark"   ] (canvas: Canvas; x, y: INTEGER);
PROCEDURE [ccall] CanvasBegin*   ["cdCanvasBegin"  ] (canvas: Canvas; mode: INTEGER);
PROCEDURE [ccall] CanvasPathSet* ["cdCanvasPathSet"] (canvas: Canvas; action: INTEGER);
PROCEDURE [ccall] CanvasEnd*     ["cdCanvasEnd"    ] (canvas: Canvas);
PROCEDURE [ccall] CanvasLine*    ["cdCanvasLine"   ] (canvas: Canvas; x1, y1, x2, y2: INTEGER);
PROCEDURE [ccall] CanvasVertex*  ["cdCanvasVertex" ] (canvas: Canvas; x, y: INTEGER);
PROCEDURE [ccall] CanvasRect*    ["cdCanvasRect"   ] (canvas: Canvas; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasBox*     ["cdCanvasBox"    ] (canvas: Canvas; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasArc*     ["cdCanvasArc"    ] (canvas: Canvas; xc, yc, w, h: INTEGER; angle1, angle2: REAL);
PROCEDURE [ccall] CanvasSector*  ["cdCanvasSector" ] (canvas: Canvas; xc, yc, w, h: INTEGER; angle1, angle2: REAL);
PROCEDURE [ccall] CanvasChord*   ["cdCanvasChord"  ] (canvas: Canvas; xc, yc, w, h: INTEGER; angle1, angle2: REAL);
PROCEDURE [ccall] CanvasText*    ["cdCanvasText"   ] (canvas: Canvas; x, y: INTEGER; s: String);
PROCEDURE [ccall] fCanvasLine*   ["cdfCanvasLine"  ] (canvas: Canvas; x1, y1, x2, y2: REAL);
PROCEDURE [ccall] fCanvasVertex* ["cdfCanvasVertex"] (canvas: Canvas; x, y: REAL);
PROCEDURE [ccall] fCanvasRect*   ["cdfCanvasRect"  ] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] fCanvasBox*    ["cdfCanvasBox"   ] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] fCanvasArc*    ["cdfCanvasArc"   ] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
PROCEDURE [ccall] fCanvasSector* ["cdfCanvasSector"] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
PROCEDURE [ccall] fCanvasChord*  ["cdfCanvasChord" ] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
PROCEDURE [ccall] fCanvasText*   ["cdfCanvasText"  ] (canvas: Canvas; x, y: REAL; s: String);

(*  attributes  *)

PROCEDURE [ccall] CanvasSetBackground*   ["cdCanvasSetBackground"  ] (canvas: Canvas; color: INTEGER);
PROCEDURE [ccall] CanvasSetForeground*   ["cdCanvasSetForeground"  ] (canvas: Canvas; color: INTEGER);
PROCEDURE [ccall] CanvasBackground*      ["cdCanvasBackground"     ] (canvas: Canvas; color: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasForeground*      ["cdCanvasForeground"     ] (canvas: Canvas; color: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasBackOpacity*     ["cdCanvasBackOpacity"    ] (canvas: Canvas; opacity: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasWriteMode*       ["cdCanvasWriteMode"      ] (canvas: Canvas; mode: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasLineStyle*       ["cdCanvasLineStyle"      ] (canvas: Canvas; style: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasLineStyleDashes* ["cdCanvasLineStyleDashes"] (canvas: Canvas; VAR dashes: INTEGER; count: INTEGER);
PROCEDURE [ccall] CanvasLineWidth*       ["cdCanvasLineWidth"      ] (canvas: Canvas; width: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasLineJoin*        ["cdCanvasLineJoin"       ] (canvas: Canvas; join: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasLineCap*         ["cdCanvasLineCap"        ] (canvas: Canvas; cap: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasInteriorStyle*   ["cdCanvasInteriorStyle"  ] (canvas: Canvas; style: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasHatch*           ["cdCanvasHatch"          ] (canvas: Canvas; style: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasStipple*         ["cdCanvasStipple"        ] (canvas: Canvas; w, h: INTEGER; stipple: String);
PROCEDURE [ccall] CanvasGetStipple*      ["cdCanvasGetStipple"     ] (canvas: Canvas; VAR n, m: INTEGER): String;
PROCEDURE [ccall] CanvasPattern*         ["cdCanvasPattern"        ] (canvas: Canvas; w, h: INTEGER; VAR pattern: INTEGER);
PROCEDURE [ccall] CanvasGetPattern*      ["cdCanvasGetPattern"     ] (canvas: Canvas; VAR n, m: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasFillMode*        ["cdCanvasFillMode"       ] (canvas: Canvas; mode: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasFont*            ["cdCanvasFont"           ] (canvas: Canvas; type_face: String; style: SET; size: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasGetFont*         ["cdCanvasGetFont"        ] (canvas: Canvas; type_face: String; VAR style, size: INTEGER);
PROCEDURE [ccall] CanvasNativeFont*      ["cdCanvasNativeFont"     ] (canvas: Canvas; font: String): String;
PROCEDURE [ccall] CanvasTextAlignment*   ["cdCanvasTextAlignment"  ] (canvas: Canvas; alignment: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasTextOrientation* ["cdCanvasTextOrientation"] (canvas: Canvas; angle: REAL): REAL;
PROCEDURE [ccall] CanvasMarkType*        ["cdCanvasMarkType"       ] (canvas: Canvas; type: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasMarkSize*        ["cdCanvasMarkSize"       ] (canvas: Canvas; size: INTEGER): INTEGER;

(*  vector text  *)

PROCEDURE [ccall] CanvasVectorText*          ["cdCanvasVectorText"         ] (canvas: Canvas; x, y: INTEGER; s: String);
PROCEDURE [ccall] CanvasMultiLineVectorText* ["cdCanvasMultiLineVectorText"] (canvas: Canvas; x, y: INTEGER; s: String);

(*  vector text attributes  *)

PROCEDURE [ccall] CanvasVectorFont*          ["cdCanvasVectorFont"         ] (canvas: Canvas; filename: String): String;
PROCEDURE [ccall] CanvasVectorTextDirection* ["cdCanvasVectorTextDirection"] (canvas: Canvas; x1, y1, x2, y2: INTEGER);
PROCEDURE [ccall] CanvasVectorTextTransform* ["cdCanvasVectorTextTransform"] (canvas: Canvas; matrix: REAL): REAL;
PROCEDURE [ccall] CanvasVectorTextSize*      ["cdCanvasVectorTextSize"     ] (canvas: Canvas; size_x, size_y: INTEGER; s: String);
PROCEDURE [ccall] CanvasVectorCharSize*      ["cdCanvasVectorCharSize"     ] (canvas: Canvas; size: INTEGER): INTEGER;
PROCEDURE [ccall] CanvasVectorFontSize*      ["cdCanvasVectorFontSize"     ] (canvas: Canvas; size_x, size_y: REAL);
PROCEDURE [ccall] CanvasGetVectorFontSize*   ["cdCanvasGetVectorFontSize"  ] (canvas: Canvas; VAR size_x, size_y: REAL);

(*  vector text properties  *)

PROCEDURE [ccall] CanvasGetVectorTextSize*    ["cdCanvasGetVectorTextSize"   ] (canvas: Canvas; s: String; VAR x, y: INTEGER);
PROCEDURE [ccall] CanvasGetVectorTextBounds*  ["cdCanvasGetVectorTextBounds" ] (canvas: Canvas; s: String; x, y: INTEGER; VAR rect: INTEGER);
PROCEDURE [ccall] CanvasGetVectorTextBox*     ["cdCanvasGetVectorTextBox"    ] (canvas: Canvas; x, y: INTEGER; s: String; VAR xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] fCanvasVectorTextDirection* ["cdfCanvasVectorTextDirection"] (canvas: Canvas; x1, y1, x2, y2: REAL);
PROCEDURE [ccall] fCanvasVectorTextSize*      ["cdfCanvasVectorTextSize"     ] (canvas: Canvas; size_x, size_y: REAL; s: String);
PROCEDURE [ccall] fCanvasGetVectorTextSize*   ["cdfCanvasGetVectorTextSize"  ] (canvas: Canvas; s: String; VAR x, y: REAL);
PROCEDURE [ccall] fCanvasVectorCharSize*      ["cdfCanvasVectorCharSize"     ] (canvas: Canvas; size: REAL): REAL;
PROCEDURE [ccall] fCanvasVectorText*          ["cdfCanvasVectorText"         ] (canvas: Canvas; x, y: REAL; s: String);
PROCEDURE [ccall] fCanvasMultiLineVectorText* ["cdfCanvasMultiLineVectorText"] (canvas: Canvas; x, y: REAL; s: String);
PROCEDURE [ccall] fCanvasGetVectorTextBounds* ["cdfCanvasGetVectorTextBounds"] (canvas: Canvas; s: String; x, y: REAL; VAR rect: REAL);
PROCEDURE [ccall] fCanvasGetVectorTextBox*    ["cdfCanvasGetVectorTextBox"   ] (canvas: Canvas; x, y: REAL; s: String; VAR xmin, xmax, ymin, ymax: REAL);

(*  properties  *)

PROCEDURE [ccall] CanvasGetFontDim*     ["cdCanvasGetFontDim"    ] (canvas: Canvas; VAR max_width, height, ascent, descent: INTEGER);
PROCEDURE [ccall] CanvasGetTextSize*    ["cdCanvasGetTextSize"   ] (canvas: Canvas; s: String; VAR width, height: INTEGER);
PROCEDURE [ccall] CanvasGetTextBox*     ["cdCanvasGetTextBox"    ] (canvas: Canvas; x, y: INTEGER; s: String; VAR xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasGetTextBounds*  ["cdCanvasGetTextBounds" ] (canvas: Canvas; x, y: INTEGER; s: String; VAR rect: INTEGER);
PROCEDURE [ccall] CanvasGetColorPlanes* ["cdCanvasGetColorPlanes"] (canvas: Canvas): INTEGER;

(*  color  *)

PROCEDURE [ccall] CanvasPalette* ["cdCanvasPalette"] (canvas: Canvas; n: INTEGER; palette: INTEGER; mode: INTEGER);

(*  client images  *)

PROCEDURE [ccall] CanvasGetImageRGB*      ["cdCanvasGetImageRGB"     ] (canvas: Canvas; r, g, b: String; x, y, w, h: INTEGER);
PROCEDURE [ccall] CanvasPutImageRectRGB*  ["cdCanvasPutImageRectRGB" ] (canvas: Canvas; iw, ih: INTEGER; r, g, b: String; x, y, w, h, xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasPutImageRectRGBA* ["cdCanvasPutImageRectRGBA"] (canvas: Canvas; iw, ih: INTEGER; r, g, b, a: String; x, y, w, h, xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasPutImageRectMap*  ["cdCanvasPutImageRectMap" ] (canvas: Canvas; iw, ih: INTEGER; index: String; colors: INTEGER; x, y, w, h, xmin, xmax, ymin, ymax: INTEGER);

(*  server images  *)

PROCEDURE [ccall] CanvasCreateImage*  ["cdCanvasCreateImage" ] (canvas: Canvas; w, h: INTEGER): Image;
PROCEDURE [ccall] KillImage*          ["cdKillImage"         ] (image: Image);
PROCEDURE [ccall] CanvasGetImage*     ["cdCanvasGetImage"    ] (canvas: Canvas; image: Image; x, y: INTEGER);
PROCEDURE [ccall] CanvasPutImageRect* ["cdCanvasPutImageRect"] (canvas: Canvas; image: Image; x, y, xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasScrollArea*   ["cdCanvasScrollArea"  ] (canvas: Canvas; xmin, xmax, ymin, ymax, dx, dy: INTEGER);

(*  bitmap  *)

PROCEDURE [ccall] CreateBitmap*    ["cdCreateBitmap"   ] (w, h, type: INTEGER): Bitmap;
PROCEDURE [ccall] InitBitmap*      ["cdInitBitmap"     ] (w, h, type: INTEGER): Bitmap;
PROCEDURE [ccall] KillBitmap*      ["cdKillBitmap"     ] (bitmap: Bitmap);
PROCEDURE [ccall] BitmapGetData*   ["cdBitmapGetData"  ] (bitmap: Bitmap; dataptr: INTEGER): String;
PROCEDURE [ccall] BitmapSetRect*   ["cdBitmapSetRect"  ] (bitmap: Bitmap; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] CanvasPutBitmap* ["cdCanvasPutBitmap"] (canvas: Canvas; bitmap: Bitmap; x, y, w, h: INTEGER);
PROCEDURE [ccall] CanvasGetBitmap* ["cdCanvasGetBitmap"] (canvas: Canvas; bitmap: Bitmap; x, y: INTEGER);
PROCEDURE [ccall] BitmapRGB2Map*   ["cdBitmapRGB2Map"  ] (bitmap_rgb, bitmap_map: Bitmap);

(*  color  *)

PROCEDURE [ccall] EncodeColor* ["cdEncodeColor"] (red, green, blue: SHORTCHAR): INTEGER;
PROCEDURE [ccall] DecodeColor* ["cdDecodeColor"] (color: INTEGER; red, green, blue: String);
PROCEDURE [ccall] DecodeAlpha* ["cdDecodeAlpha"] (color: INTEGER): SHORTCHAR;
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

(* World Coordinate Functions *)

(* coordinate transformation *)
PROCEDURE [ccall] wdCanvasWindow*              ["wdCanvasWindow"             ] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] wdCanvasGetWindow*           ["wdCanvasGetWindow"          ] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] wdCanvasViewport*            ["wdCanvasViewport"           ] (canvas: Canvas; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] wdCanvasGetViewport*         ["wdCanvasGetViewport"        ] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] wdCanvasWorld2Canvas*        ["wdCanvasWorld2Canvas"       ] (canvas: Canvas; xw, yw: REAL; VAR xv, yv: INTEGER);
PROCEDURE [ccall] wdCanvasWorld2CanvasSize*    ["wdCanvasWorld2CanvasSize"   ] (canvas: Canvas; hw, vw: REAL; VAR hv, vv: INTEGER);
PROCEDURE [ccall] wdCanvasCanvas2World*        ["wdCanvasCanvas2World"       ] (canvas: Canvas; xv, yv: INTEGER; VAR xw, yw: REAL);
PROCEDURE [ccall] wdCanvasSetTransform*        ["wdCanvasSetTransform"       ] (canvas: Canvas; sx, sy, tx, ty: REAL);
PROCEDURE [ccall] wdCanvasGetTransform*        ["wdCanvasGetTransform"       ] (canvas: Canvas; VAR sx, sy, tx, ty: REAL);
PROCEDURE [ccall] wdCanvasTranslate*           ["wdCanvasTranslate"          ] (canvas: Canvas; dtx, dty: REAL);
PROCEDURE [ccall] wdCanvasScale*               ["wdCanvasScale"              ] (canvas: Canvas; dsx, dsy: REAL);
PROCEDURE [ccall] wdCanvasClipArea*            ["wdCanvasClipArea"           ] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] wdCanvasGetClipArea*         ["wdCanvasGetClipArea"        ] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: REAL): INTEGER;
PROCEDURE [ccall] wdCanvasIsPointInRegion*     ["wdCanvasIsPointInRegion"    ] (canvas: Canvas; x, y: REAL): INTEGER;
PROCEDURE [ccall] wdCanvasOffsetRegion*        ["wdCanvasOffsetRegion"       ] (canvas: Canvas; x, y: REAL);
PROCEDURE [ccall] wdCanvasGetRegionBox*        ["wdCanvasGetRegionBox"       ] (canvas: Canvas; VAR xmin, xmax, ymin, ymax: REAL);
(* primitives *)
PROCEDURE [ccall] wdCanvasPixel*               ["wdCanvasPixel"              ] (canvas: Canvas; x, y: REAL; color: INTEGER);
PROCEDURE [ccall] wdCanvasMark*                ["wdCanvasMark"               ] (canvas: Canvas; x, y: REAL);
PROCEDURE [ccall] wdCanvasLine*                ["wdCanvasLine"               ] (canvas: Canvas; x1, y1, x2, y2: REAL);
PROCEDURE [ccall] wdCanvasVertex*              ["wdCanvasVertex"             ] (canvas: Canvas; x, y: REAL);
PROCEDURE [ccall] wdCanvasRect*                ["wdCanvasRect"               ] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] wdCanvasBox*                 ["wdCanvasBox"                ] (canvas: Canvas; xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] wdCanvasArc*                 ["wdCanvasArc"                ] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
PROCEDURE [ccall] wdCanvasSector*              ["wdCanvasSector"             ] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
PROCEDURE [ccall] wdCanvasChord*               ["wdCanvasChord"              ] (canvas: Canvas; xc, yc, w, h, angle1, angle2: REAL);
PROCEDURE [ccall] wdCanvasText*                ["wdCanvasText"               ] (canvas: Canvas; x, y: REAL; s: String);
PROCEDURE [ccall] wdCanvasPutImageRect*        ["wdCanvasPutImageRect"       ] (canvas: Canvas; image: Image; x, y: REAL; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] wdCanvasPutImageRectRGB*     ["wdCanvasPutImageRectRGB"    ] (canvas: Canvas; iw, ih: INTEGER; r, g, b: String; x, y, w, h: REAL; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] wdCanvasPutImageRectRGBA*    ["wdCanvasPutImageRectRGBA"   ] (canvas: Canvas; iw, ih: INTEGER; r, g, b, a: String; x, y, w, h: REAL; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] wdCanvasPutImageRectMap*     ["wdCanvasPutImageRectMap"    ] (canvas: Canvas; iw, ih: INTEGER; index: String; colors: INTEGER; x, y, w, h: REAL; xmin, xmax, ymin, ymax: INTEGER);
PROCEDURE [ccall] wdCanvasPutBitmap*           ["wdCanvasPutBitmap"          ] (canvas: Canvas; bitmap: Bitmap; x, y, w, h: REAL);
(* attributes *)
PROCEDURE [ccall] wdCanvasLineWidth*           ["wdCanvasLineWidth"          ] (canvas: Canvas; width: REAL): REAL;
PROCEDURE [ccall] wdCanvasFont*                ["wdCanvasFont"               ] (canvas: Canvas; type_face: String; style: INTEGER; size: REAL): INTEGER;
PROCEDURE [ccall] wdCanvasGetFont*             ["wdCanvasGetFont"            ] (canvas: Canvas; type_face: String; VAR style: INTEGER; VAR size: REAL);
PROCEDURE [ccall] wdCanvasMarkSize*            ["wdCanvasMarkSize"           ] (canvas: Canvas; size: REAL): REAL;
PROCEDURE [ccall] wdCanvasGetFontDim*          ["wdCanvasGetFontDim"         ] (canvas: Canvas; VAR max_width, height, ascent, descent: REAL);
PROCEDURE [ccall] wdCanvasGetTextSize*         ["wdCanvasGetTextSize"        ] (canvas: Canvas; s: String; VAR width, height: REAL);
PROCEDURE [ccall] wdCanvasGetTextBox*          ["wdCanvasGetTextBox"         ] (canvas: Canvas; x, y: REAL; s: String; VAR xmin, xmax, ymin, ymax: REAL);
PROCEDURE [ccall] wdCanvasGetTextBounds*       ["wdCanvasGetTextBounds"      ] (canvas: Canvas; x, y: REAL; s: String; VAR rect: REAL);
PROCEDURE [ccall] wdCanvasStipple*             ["wdCanvasStipple"            ] (canvas: Canvas; w, h: INTEGER; fgbg: String; w_mm, h_mm: REAL);
PROCEDURE [ccall] wdCanvasPattern*             ["wdCanvasPattern"            ] (canvas: Canvas; w, h: INTEGER; color: INTEGER; w_mm, h_mm: REAL);
(* vector text *)
PROCEDURE [ccall] wdCanvasVectorTextDirection* ["wdCanvasVectorTextDirection"] (canvas: Canvas; x1, y1, x2, y2: REAL);
PROCEDURE [ccall] wdCanvasVectorTextSize*      ["wdCanvasVectorTextSize"     ] (canvas: Canvas; size_x, size_y: REAL; s: String);
PROCEDURE [ccall] wdCanvasGetVectorTextSize*   ["wdCanvasGetVectorTextSize"  ] (canvas: Canvas; s: String; VAR x, y: REAL);
PROCEDURE [ccall] wdCanvasVectorCharSize*      ["wdCanvasVectorCharSize"     ] (canvas: Canvas; size: REAL): REAL;
PROCEDURE [ccall] wdCanvasVectorText*          ["wdCanvasVectorText"         ] (canvas: Canvas; x, y: REAL; s: String);
PROCEDURE [ccall] wdCanvasMultiLineVectorText* ["wdCanvasMultiLineVectorText"] (canvas: Canvas; x, y: REAL; s: String);
PROCEDURE [ccall] wdCanvasGetVectorTextBounds* ["wdCanvasGetVectorTextBounds"] (canvas: Canvas; s: String; x, y: REAL; VAR rect: REAL);
PROCEDURE [ccall] wdCanvasGetVectorTextBox*    ["wdCanvasGetVectorTextBox"   ] (canvas: Canvas; x, y: REAL; s: String; VAR xmin, xmax, ymin, ymax: REAL);

BEGIN
END CdLib.
