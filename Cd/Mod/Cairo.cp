MODULE CdCairo ["cdcairo"];
IMPORT Cd := CdLib;

PROCEDURE [ccall] ContextNativeWindow* ["cdContextCairoNativeWindow"] (): Cd.Context;
PROCEDURE [ccall] ContextImage*        ["cdContextCairoImage"       ] (): Cd.Context;
PROCEDURE [ccall] ContextDBuffer*      ["cdContextCairoDBuffer"     ] (): Cd.Context;
PROCEDURE [ccall] ContextPrinter*      ["cdContextCairoPrinter"     ] (): Cd.Context;
PROCEDURE [ccall] ContextPS*           ["cdContextCairoPS"          ] (): Cd.Context;
PROCEDURE [ccall] ContextPDF*          ["cdContextCairoPDF"         ] (): Cd.Context;
PROCEDURE [ccall] ContextSVG*          ["cdContextCairoSVG"         ] (): Cd.Context;
PROCEDURE [ccall] ContextImageRGB*     ["cdContextCairoImageRGB"    ] (): Cd.Context;
PROCEDURE [ccall] ContextEMF*          ["cdContextCairoEMF"         ] (): Cd.Context;
	
END CdCairo.