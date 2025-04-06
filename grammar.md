\<Program> ::= { \<GlobalStatement> }


\<GlobalStatement> ::= \<VarDeclaration> | \<Function>


<VarDeclaration> ::= "var" <Identifier> ":" <Type> ["=" <Expression>] ";"


<Type> ::= "Int" | "Boolean" | "Double" | "String"

<Function> ::= "fun" <Identifier> "(" [<Parameters>] ")" ":" <Type> <Block>
<Parameters> ::= <Parameter> { "," <Parameter> }
<Parameter> ::= <Identifier> ":" <Type>
<Block> ::= "{" { <Statement> } "}"

<Statement> ::= <VarDeclaration> | <Assignment> | <IfStatement> | <WhileLoop> | <ForLoop> | <ReturnStatement> | <Expression> ";"
<Assignment> ::= <Identifier> "=" <Expression> ";"
<ReturnStatement> ::= "return" <Expression> ";"

<IfStatement> ::= "if" "(" <Expression> ")" <Block> ["else" <Block>]

<WhileLoop> ::= "while" "(" <Expression> ")" <Block>

<ForLoop> ::= "for" "(" <Identifier> "in" <Range> ["step" <Number>] ")" <Block>
<Range> ::= <Expression> ".." <Expression>

<Expression> ::= <LogicalOr>
<LogicalOr> ::= <LogicalAnd> { "||" <LogicalAnd> }
<LogicalAnd> ::= <Equality> { "&&" <Equality> }
<Equality> ::= <Comparison> { ("==" | "!=") <Comparison> }
<Comparison> ::= <AddSub> { ("<" | ">" | "<=" | ">=") <AddSub> }
<AddSub> ::= <MulDiv> { ("+" | "-") <MulDiv> }
<MulDiv> ::= <Primary> { ("*" | "/") <Primary> }
<Primary> ::= <Number> | <Boolean> | <Identifier> | <FunctionCall> | <StringIndex> | <StringProperty> | "(" <Expression> ")"
<FunctionCall> ::= <Identifier> "(" [<Arguments>] ")" | <Identifier> "." "substring" "(" <Arguments> ")"
<Arguments> ::= <Expression> { "," <Expression> }
<StringIndex> ::= <Identifier> "[" <Expression> "]"
<StringProperty> ::= <Identifier> "." "lenght"

<Number> ::= <Digit>+
<Boolean> ::= "true" | "false"