typedef enum
{
  ND_ADD,    //+
  ND_SUB,    //-
  ND_MUL,    //*
  ND_DIV,    // /
  ND_EQ,     // ==
  ND_NE,     // !=
  ND_LT,     // <
  ND_LE,     // <=
  ND_NUM,    // 整数
  ND_ASSIGN, // =
  ND_LVAR,   // ローカル変数
  ND_RETURN, // return
} NodeKind;

typedef struct Node Node;

struct Node
{
  NodeKind kind; // ノードの種類
  Node *lhs;     // 左辺のノード
  Node *rhs;     // 右辺のノード
  int val;       // kindがND_NUMの場合のみ使う
  int offset;    // kindがND_LVARの場合のみ使う
};

// トークンの種類
typedef enum
{
  TK_RESERVED, // 記号
  TK_IDENT,    // 識別子
  TK_NUM,      // 整数トークン
  TK_EOF,      // 入力の終わりを表すトークン
  TK_RETURN    // return
} TokenKind;

typedef struct Token Token;

struct Token
{
  TokenKind kind;
  Token *next;
  int val;
  char *str;
  int len;
};

typedef struct LVar LVar;

struct LVar
{
  LVar *next; // 次の変数かNULL
  char *name; // 変数の名前
  int len;    // 名前の長さ
  int offset; // RBPからのオフセット
};

extern void
program(void);
extern Node *expr(void);
extern Token *tokenize(char *p);

extern void gen(Node *node);

extern char *user_input;
extern Token *token;
extern Node *code[100];
extern LVar *locals;

extern void error_at(char *loc, char *fmt, ...);
extern void error(char *fmt, ...);