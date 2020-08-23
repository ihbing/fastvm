﻿
#include "slgh_compile.h"

SleighCompile *slgh = NULL;
#ifdef YYDEBUG
extern in yydebug;
#endif
extern FILE *yyin;
extern int yyparse(void);
int yylex_destroy(void) {
    return 0;
}

struct slgh_macro* slgh_get_macro1(SleighCompile *slgh, const char *sym)
{
    struct slgh_macro *macro;
    int i;
    mlist_for_each(slgh->defines, macro, in_list, i) {
        if (!strcmp(macro->name, sym))
            return macro;
    }

    return NULL;
}

bool                slgh_get_macro(SleighCompile *s, char *name, char **val)
{
    struct slgh_macro *m = slgh_get_macro1(slgh, name);

    if (m) {
        if (val)
            *val = m->value;
        return true;
    }

    return false;
}

void                slgh_set_macro(SleighCompile *s, char *name, char *val)
{
    int len1, len2;
    struct slgh_macro *macro;
    if ((macro = slgh_get_macro1(slgh, name))) {
        vm_error("redefine macro %s\n", name);
    }

    len1 = strlen(name);
    len2 = val ? strlen(val):0;

    macro = vm_mallocz(sizeof (macro[0]) + len1 + len2 + 1);
    strcpy(macro->name, name);
    if (val)
        strcpy(macro->name + len1 + 1, val);

    mlist_add(slgh->defines, macro, in_list);
}

bool                slgh_del_macro(SleighCompile *s, char *name)
{
    struct slgh_macro *macro = slgh_get_macro1(slgh, name);

    if (!macro) {
        vm_warn("undefined macro[%s] not exist", name);
        return false;
    }

    mlist_del(slgh->defines, macro, in_list);
    free(macro);

    return true;
}

SpaceQuality*   SpaceQuality_new(char *name)
{
    return NULL;
}

SleighCompile*  SleighCompile_new()
{
    SleighCompile *slgh = vm_mallocz(sizeof (slgh[0]));

    return slgh;
}

void            SleighCompile_delete(SleighCompile *slgh)
{
    struct slgh_macro *macro;

    while ((macro = slgh->defines.list)) {
        mlist_del(slgh->defines, macro, in_list);
        free(macro);
    }

    free(slgh);
}

SleighCompile*  SleighArch_register()
{
    return NULL;
}

void            SleighCompile_resetConstructor(SleighCompile *s)
{
}

void            SleighCompile_setEndian(SleighCompile *s, int e)
{
}

void            SleighCompile_setAlignment(SleighCompile *s, int e)
{
}

TokenSymbol*    SleighCompile_defineToken(SleighCompile *s, const char *name, intb sz)
{
    return NULL;
}

void            SleighCompile_addTokenField(SleighCompile *s, TokenSymbol *sym, FieldQuality *qual)
{
}

bool            SleighCompile_addContextField(SleighCompile *s, VarnodeSymbol *sym, FieldQuality *qual)
{
    return TRUE;
}

void            SleighCompile_newSpace(SleighCompile *s, SpaceQuality *quad)
{
}

void            SleighCompile_defineVarnodes(SleighCompile *s, SpaceSymbol *sym, uintb off, uintb size, struct dynarray *names)
{
}

void            SleighCompile_defineBitrange(SleighCompile *s, const char *name, VarnodeSymbol *sym, uint32_t bitoffset, uint32_t numb)
{

}

void            SleighCompile_defineOperand(SleighCompile *s, OperandSymbol *sym, PatternExpression *exp)
{

}

void            SleighCompile_addUserOp(SleighCompile *s, struct dynarray *names)
{

}

void            SleighCompile_attachValues(SleighCompile *s, struct dynarray *symlist, struct dynarray *numlist)
{

}

void            SleighCompile_attachNames(SleighCompile *s, struct dynarray *symlist, struct dynarray *names)
{

}

void            SleighCompile_attachVarnodes(SleighCompile *s, struct dynarray *symlist, struct dynarray *varlist)
{

}

void            SleighCompile_buildMacro(SleighCompile *s, MacroSymbol *sym, ConstructTpl *tpl)
{

}

void            SleighCompile_pushWith(SleighCompile *s, SubtableSymbol *sym, PatternEquation *pateq, struct dynarray *contvec)
{

}

void            SleighCompile_popWith(SleighCompile *s)
{

}

SubtableSymbol* SleighCompile_newTable(SleighCompile *s, const char *name)
{
    return NULL;
}

MacroSymbol*    SleighCompile_createMacro(SleighCompile *s, const char *name, struct dynarray *param)
{
    return NULL;
}

SectionVector*  SleighCompile_standaloneSection(SleighCompile *s, ConstructTpl *main)
{
    return NULL;
}

SectionVector*  SleighCompile_firstNamedSection(SleighCompile *s, ConstructTpl *main, SectionSymbol *sym)
{
    return NULL;
}

SectionVector*  SleighCompile_nextNamedSection(SleighCompile *s, SectionVector *vec, ConstructTpl *section, SectionSymbol *sym)
{
    return NULL;
}

void            SleighCompile_buildConstructor(SleighCompile *s, Constructor *big, PatternEquation *pateq, struct dynarray *contvec, SectionVector *vec)
{

}

void            SleighCompile_newOperand(SleighCompile *s, Constructor *c, const char *name)
{

}

Constructor*        SleighCompile_createConstructor(SleighCompile *s, SubtableSymbol *sym)
{
    return NULL;
}

PatternEquation*    SleighCompile_constrainOperand(SleighCompile *s, OperandSymbol *sym, PatternExpression *patexp)
{
    return NULL;
}

void                SleighCompile_selfDefine(SleighCompile *s, OperandSymbol *sym)
{

}

PatternEquation*    SleighCompile_defineInvisibleOperand(SleighCompile *s, TripleSymbol *sym)
{
    return NULL;
}

bool                SleighCompile_contextMod(SleighCompile *s, struct dynarray *vec, ContextSymbol *sym, PatternExpression *pe)
{
    return true;
}

void                SleighCompile_contextSet(SleighCompile *s, struct dynarray *vec, TripleSymbol *sym, ContextSymbol *ctxSym)
{
}

SectionSymbol*      SleighCompile_newSectionSymbol(SleighCompile *s, char *name)
{
    return NULL;
}

void                SleighCompile_recordNop(SleighCompile *s)
{

}

void                SleighCompile_addRegister(SleighCompile *s, const char *name, AddrSpace *base, uintb offset, int size)
{

}

const char*         SleighCompile_getRegisterName(SleighCompile *s, AddrSpace *base, uintb off, int size)
{
    return NULL;
}

void                SleighCompile_getAllRegister(SleighCompile *s, struct dynarray *d)
{
}

void                SleighCompile_getUserOpNames(SleighCompile *s, struct dynarray *d)
{

}

ConstructTpl*       SleighCompile_setResultVarnode(SleighCompile *s, ConstructTpl *ct, VarnodeTpl *vn)
{
    return NULL;
}

ConstructTpl*       SleighCompile_setResultStarVarnode(SleighCompile *s, ConstructTpl *ct, StarQuality *star, VarnodeTpl *vn)
{
    return NULL;
}

struct dynarray*    SleighCompile_createCrossBuild(SleighCompile *s, VarnodeTpl *addr, SectionSymbol *sym)
{
    return NULL;
}

struct dynarray*    SleighCompile_createMacroUse(SleighCompile *s, MacroSymbol *sym, struct dynarray *param)
{
    return NULL;
}

bool                SleighCompile_getPreprocValue(SleighCompile *s, char *name, char **value)
{
    return true;
}

void                SleighCompile_setPreprocValue(SleighCompile *s, char *name, char *value)
{
}

bool                SleighCompile_undefinePreprocValue(SleighCompile *s, char *name)
{
    return false;
}

void                SleighCompile_parseFromNewFile(SleighCompile *s, const char *fname)
{
    struct slgh_preproc *proc = vm_mallocz(sizeof (proc[0]));
    char *base;

    proc->lineno = 1;

    if (slgh->preproc.len && !IS_ABSPATH(fname)) {
        struct slgh_preproc *last = dynarray_back(&slgh->preproc);
        base = basename(last->fullpath.data);
        cstr_cat(&proc->fullpath, last->fullpath.data, base - last->fullpath.data);
    }

    cstr_cat(&proc->fullpath, fname, strlen(fname));

    dynarray_add(&s->preproc, proc);
}

void                SleighCompile_parsePreprocMacro(SleighCompile *s)
{
    struct slgh_preproc *last = dynarray_back(&s->preproc);
    struct slgh_preproc *proc = vm_mallocz(sizeof (proc[0]));

    cstr_cat(&proc->fullpath, last->fullpath.data, last->fullpath.size);
    cstr_cat(&proc->fullpath, ":macro", 0);

    proc->lineno = last->lineno;
    dynarray_add(&s->preproc, proc);
}

void                SleighCompile_parseFileFinished(SleighCompile *s)
{
    vm_free(dynarray_back(&s->preproc));
    dynarray_pop(&s->preproc);
}

char*               SleighCompile_grabCurrentFilePath(SleighCompile *s)
{
    if (!s->preproc.len) return "";
    char *s1 = ((struct slgh_preproc *)dynarray_back(&s->preproc))->fullpath.data;

    return s1;
}

SleighSymbol*       SleighCompile_findSymbol(SleighCompile *s, char *name)
{
    return NULL;
}

void                SleighCompile_nextLine(SleighCompile *s)
{
}

void                SleighCompile_calcContextLayout(SleighCompile *s)
{
}

FieldQuality*   FieldQuality_new(const char *name, uintb l, uintb h)
{
    return NULL;
}

SectionVector*  SleighCompile_finalNamedSection(SleighCompile *s, SectionVector *vec, ConstructTpl *section)
{
    return NULL;
}

void    SleighCompile_checkNops(SleighCompile *s)
{
}

void    SleighCompile_checkConsistency(SleighCompile *s)
{
}

void    SleighCompile_process(SleighCompile *s)
{
    SleighCompile_checkNops(s);
    if (!s->defaultcodespace)
        vm_error("No default code space");
    if (s->errors > 0) return;
}

static char help[] = {
    "USAGE: sleigh [-x] [-dNAME=VALUE] inputfile [outputfile]\n" 
    "   -a              scan for all slaspec files recursively where inputfile is a directory\n" 
    "   -x              turns on parser debugging\n" 
    "   -u              print warnings for unnecessary pcode instructions\n"
    "   -l              report pattern conflicts\n" 
    "   -n              print warnings for all NOP constructors\n" 
    "   -t              print warnings for dead temporaries\n" 
    "   -e              enforce use of 'local' keyword for temporaries\n" 
    "   -c              print warnings for all constructors with colliding operands\n" 
    "   -DNAME=VALUE    defines a preprocessor macro NAME with value VALUE\n" 
};

int                 slgh_run(SleighCompile *s, const char *filein, const char *fileout)
{
    slgh = s;

    SleighCompile_parseFromNewFile(s, filein);

    yyin = fopen(filein, "r");
    if (NULL == yyin) 
        vm_error("unable to open specfile: %s", filein);

    int parseres = yyparse();
    fclose(yyin);

    FILE *out = fopen(fileout, "w");
    if (!out)
        vm_error("fopen(%s) failure", fileout);
    slgh->saveXml(s, out);
    fclose(out);

    yylex_destroy();

    return 0;
}

int             slgh_run_xml(SleighCompile *s, const char *filein)
{
    return 0;
}

#if defined(SLEIGH_EXE)
int                 main(int argc, char **argv)
{
    int i;
    bool compileAll = false;
    SleighCompile *slgh = SleighCompile_new(0);
    char *p, *newstr, *sym, *val;

    if (argc < 2) {
        puts(help);
        exit(2);
    }

    for (i = 1; i < argc; i++) {
        p = argv[i];
        if (*p != '_') break;
        else if (p[1] == 'a')
            compileAll = true;
        else if (p[1] == 'D') {
            newstr = strdup(p);
            val = strchr(newstr, '=');
            sym = p + 2;
            if (val) {
                *val = 0;
                val++;
            }
            slgh_define_macro(slgh, sym, val);

            free(p);
        }
        else if (p[1] == 'u')
            slgh->warnunnecessarypcode = true;
        else if (p[1] == 'l')
            slgh->lenientconfliciterros = true;
        else if (p[1] == 'c')
            slgh->warnallocalcollisions = true;
        else if (p[1] == 'n')
            slgh->warnallnops = true;
        else if (p[1] == 't')
            slgh->warndeadtemps = true;
        else if (p[1] == 'e')
            PcodeCompile_setEnforceLocalKey(slgh->pcode, true);
        else {
            printf("Unknown option %s\n", p);
            return;
        }
    }

    char *filein = argv[i];
    CString cs = {0};

    if (compileAll) {
    }
    else {
        char *ext = strrchr(filein, '.');
        cstr_cat(&cs, filein, ext - filein);
        cstr_cat(&cs, ".sla", 4);
        if (!strcmp(ext, ".xml")) {
        }
        else if (!strcmp(ext, ".slaspec")) {
            return slgh_run(slgh, filein, cs.data);
        }
        else {
            printf("Unkown file %s\n", filein);
            return -1;
        }
    }
    cstr_free(&cs);

    SleighCompile_delete(slgh);

    return 0;
}
#endif