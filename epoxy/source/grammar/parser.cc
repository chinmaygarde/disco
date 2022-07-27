// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   epoxy_lex



#include "parser.h"


// Unqualified %code blocks.

#include "decls.h"



#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if EPOXY_DEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !EPOXY_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !EPOXY_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace epoxy {

  /// Build a parser object.
  Parser::Parser (epoxy::Driver& driver_yyarg, void *scanner_yyarg)
#if EPOXY_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg),
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Enum: // Enum
        value.YY_MOVE_OR_COPY< epoxy::Enum > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Function: // Function
        value.YY_MOVE_OR_COPY< epoxy::Function > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Namespace: // Namespace
        value.YY_MOVE_OR_COPY< epoxy::Namespace > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NamespaceItem: // NamespaceItem
        value.YY_MOVE_OR_COPY< epoxy::NamespaceItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NamespaceItems: // NamespaceItems
        value.YY_MOVE_OR_COPY< epoxy::NamespaceItems > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Primitive: // Primitive
        value.YY_MOVE_OR_COPY< epoxy::Primitive > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Struct: // Struct
        value.YY_MOVE_OR_COPY< epoxy::Struct > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Variable: // Variable
        value.YY_MOVE_OR_COPY< epoxy::Variable > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "<identifier>"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PrimitiveOrIdentifier: // PrimitiveOrIdentifier
        value.YY_MOVE_OR_COPY< std::variant<Primitive, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ArgumentList: // ArgumentList
      case symbol_kind::S_VariableList: // VariableList
        value.YY_MOVE_OR_COPY< std::vector<epoxy::Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IdentifierList: // IdentifierList
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Enum: // Enum
        value.move< epoxy::Enum > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Function: // Function
        value.move< epoxy::Function > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Namespace: // Namespace
        value.move< epoxy::Namespace > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NamespaceItem: // NamespaceItem
        value.move< epoxy::NamespaceItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NamespaceItems: // NamespaceItems
        value.move< epoxy::NamespaceItems > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Primitive: // Primitive
        value.move< epoxy::Primitive > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Struct: // Struct
        value.move< epoxy::Struct > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Variable: // Variable
        value.move< epoxy::Variable > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "<identifier>"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PrimitiveOrIdentifier: // PrimitiveOrIdentifier
        value.move< std::variant<Primitive, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ArgumentList: // ArgumentList
      case symbol_kind::S_VariableList: // VariableList
        value.move< std::vector<epoxy::Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IdentifierList: // IdentifierList
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Enum: // Enum
        value.copy< epoxy::Enum > (that.value);
        break;

      case symbol_kind::S_Function: // Function
        value.copy< epoxy::Function > (that.value);
        break;

      case symbol_kind::S_Namespace: // Namespace
        value.copy< epoxy::Namespace > (that.value);
        break;

      case symbol_kind::S_NamespaceItem: // NamespaceItem
        value.copy< epoxy::NamespaceItem > (that.value);
        break;

      case symbol_kind::S_NamespaceItems: // NamespaceItems
        value.copy< epoxy::NamespaceItems > (that.value);
        break;

      case symbol_kind::S_Primitive: // Primitive
        value.copy< epoxy::Primitive > (that.value);
        break;

      case symbol_kind::S_Struct: // Struct
        value.copy< epoxy::Struct > (that.value);
        break;

      case symbol_kind::S_Variable: // Variable
        value.copy< epoxy::Variable > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "<identifier>"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_PrimitiveOrIdentifier: // PrimitiveOrIdentifier
        value.copy< std::variant<Primitive, std::string> > (that.value);
        break;

      case symbol_kind::S_ArgumentList: // ArgumentList
      case symbol_kind::S_VariableList: // VariableList
        value.copy< std::vector<epoxy::Variable> > (that.value);
        break;

      case symbol_kind::S_IdentifierList: // IdentifierList
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Enum: // Enum
        value.move< epoxy::Enum > (that.value);
        break;

      case symbol_kind::S_Function: // Function
        value.move< epoxy::Function > (that.value);
        break;

      case symbol_kind::S_Namespace: // Namespace
        value.move< epoxy::Namespace > (that.value);
        break;

      case symbol_kind::S_NamespaceItem: // NamespaceItem
        value.move< epoxy::NamespaceItem > (that.value);
        break;

      case symbol_kind::S_NamespaceItems: // NamespaceItems
        value.move< epoxy::NamespaceItems > (that.value);
        break;

      case symbol_kind::S_Primitive: // Primitive
        value.move< epoxy::Primitive > (that.value);
        break;

      case symbol_kind::S_Struct: // Struct
        value.move< epoxy::Struct > (that.value);
        break;

      case symbol_kind::S_Variable: // Variable
        value.move< epoxy::Variable > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "<identifier>"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_PrimitiveOrIdentifier: // PrimitiveOrIdentifier
        value.move< std::variant<Primitive, std::string> > (that.value);
        break;

      case symbol_kind::S_ArgumentList: // ArgumentList
      case symbol_kind::S_VariableList: // VariableList
        value.move< std::vector<epoxy::Variable> > (that.value);
        break;

      case symbol_kind::S_IdentifierList: // IdentifierList
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if EPOXY_DEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if EPOXY_DEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // EPOXY_DEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
{

}



    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver, scanner));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_Enum: // Enum
        yylhs.value.emplace< epoxy::Enum > ();
        break;

      case symbol_kind::S_Function: // Function
        yylhs.value.emplace< epoxy::Function > ();
        break;

      case symbol_kind::S_Namespace: // Namespace
        yylhs.value.emplace< epoxy::Namespace > ();
        break;

      case symbol_kind::S_NamespaceItem: // NamespaceItem
        yylhs.value.emplace< epoxy::NamespaceItem > ();
        break;

      case symbol_kind::S_NamespaceItems: // NamespaceItems
        yylhs.value.emplace< epoxy::NamespaceItems > ();
        break;

      case symbol_kind::S_Primitive: // Primitive
        yylhs.value.emplace< epoxy::Primitive > ();
        break;

      case symbol_kind::S_Struct: // Struct
        yylhs.value.emplace< epoxy::Struct > ();
        break;

      case symbol_kind::S_Variable: // Variable
        yylhs.value.emplace< epoxy::Variable > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "<identifier>"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_PrimitiveOrIdentifier: // PrimitiveOrIdentifier
        yylhs.value.emplace< std::variant<Primitive, std::string> > ();
        break;

      case symbol_kind::S_ArgumentList: // ArgumentList
      case symbol_kind::S_VariableList: // VariableList
        yylhs.value.emplace< std::vector<epoxy::Variable> > ();
        break;

      case symbol_kind::S_IdentifierList: // IdentifierList
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4: // NamespaceList: Namespace
                              { driver.AddNamespace(yystack_[0].value.as < epoxy::Namespace > ()); }
    break;

  case 5: // NamespaceList: NamespaceList Namespace
                              { driver.AddNamespace(yystack_[0].value.as < epoxy::Namespace > ()); }
    break;

  case 6: // Namespace: "namespace" "<identifier>" "{" NamespaceItems "}"
                                                               { yylhs.value.as < epoxy::Namespace > () = epoxy::Namespace{yystack_[3].value.as < std::string > (), yystack_[1].value.as < epoxy::NamespaceItems > ()}; }
    break;

  case 7: // Namespace: "namespace" "<identifier>" "{" "}"
                                                               { yylhs.value.as < epoxy::Namespace > () = epoxy::Namespace{yystack_[2].value.as < std::string > (), {}}; }
    break;

  case 8: // NamespaceItems: NamespaceItem
                                   { yylhs.value.as < epoxy::NamespaceItems > () = {yystack_[0].value.as < epoxy::NamespaceItem > ()}; }
    break;

  case 9: // NamespaceItems: NamespaceItems NamespaceItem
                                   { yylhs.value.as < epoxy::NamespaceItems > () = yystack_[1].value.as < epoxy::NamespaceItems > (); yylhs.value.as < epoxy::NamespaceItems > ().push_back(yystack_[0].value.as < epoxy::NamespaceItem > ()); }
    break;

  case 10: // NamespaceItem: Function
              { yylhs.value.as < epoxy::NamespaceItem > () = yystack_[0].value.as < epoxy::Function > (); }
    break;

  case 11: // NamespaceItem: Struct
              { yylhs.value.as < epoxy::NamespaceItem > () = yystack_[0].value.as < epoxy::Struct > (); }
    break;

  case 12: // NamespaceItem: Enum
              { yylhs.value.as < epoxy::NamespaceItem > () = yystack_[0].value.as < epoxy::Enum > (); }
    break;

  case 13: // Enum: "enum" "<identifier>" "{" "}"
                                                          { yylhs.value.as < epoxy::Enum > () = epoxy::Enum{yystack_[2].value.as < std::string > (), {}}; }
    break;

  case 14: // Enum: "enum" "<identifier>" "{" IdentifierList "}"
                                                          { yylhs.value.as < epoxy::Enum > () = epoxy::Enum{yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<std::string> > ()}; }
    break;

  case 15: // IdentifierList: "<identifier>" ","
                                           { yylhs.value.as < std::vector<std::string> > () = {yystack_[1].value.as < std::string > ()}; }
    break;

  case 16: // IdentifierList: "<identifier>"
                                           { yylhs.value.as < std::vector<std::string> > () = {yystack_[0].value.as < std::string > ()}; }
    break;

  case 17: // IdentifierList: IdentifierList "<identifier>" ","
                                           { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[1].value.as < std::string > ()); }
    break;

  case 18: // IdentifierList: IdentifierList "<identifier>"
                                           { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); }
    break;

  case 19: // Function: "function" "<identifier>" "(" ArgumentList ")" "->" PrimitiveOrIdentifier
                                                                                             { yylhs.value.as < epoxy::Function > () = epoxy::Function{yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::vector<epoxy::Variable> > (), yystack_[0].value.as < std::variant<Primitive, std::string> > (), false}; }
    break;

  case 20: // Function: "function" "<identifier>" "(" ArgumentList ")" "->" PrimitiveOrIdentifier "*"
                                                                                             { yylhs.value.as < epoxy::Function > () = epoxy::Function{yystack_[6].value.as < std::string > (), yystack_[4].value.as < std::vector<epoxy::Variable> > (), yystack_[1].value.as < std::variant<Primitive, std::string> > (), true}; }
    break;

  case 21: // Function: "function" "<identifier>" "(" ArgumentList ")"
                                                                                             { yylhs.value.as < epoxy::Function > () = epoxy::Function{yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<epoxy::Variable> > (), epoxy::Primitive::kVoid, false}; }
    break;

  case 22: // Function: "function" "<identifier>" "(" ")" "->" PrimitiveOrIdentifier
                                                                                             { yylhs.value.as < epoxy::Function > () = epoxy::Function{yystack_[4].value.as < std::string > (), {}, yystack_[0].value.as < std::variant<Primitive, std::string> > (), false}; }
    break;

  case 23: // Function: "function" "<identifier>" "(" ")" "->" PrimitiveOrIdentifier "*"
                                                                                             { yylhs.value.as < epoxy::Function > () = epoxy::Function{yystack_[5].value.as < std::string > (), {}, yystack_[1].value.as < std::variant<Primitive, std::string> > (), true}; }
    break;

  case 24: // Function: "function" "<identifier>" "(" ")"
                                                                                             { yylhs.value.as < epoxy::Function > () = epoxy::Function{yystack_[2].value.as < std::string > (), {}, epoxy::Primitive::kVoid, false}; }
    break;

  case 25: // PrimitiveOrIdentifier: Primitive
                    { yylhs.value.as < std::variant<Primitive, std::string> > () = yystack_[0].value.as < epoxy::Primitive > (); }
    break;

  case 26: // PrimitiveOrIdentifier: "<identifier>"
                    { yylhs.value.as < std::variant<Primitive, std::string> > () = yystack_[0].value.as < std::string > (); }
    break;

  case 27: // ArgumentList: Variable
                                    { yylhs.value.as < std::vector<epoxy::Variable> > () = {yystack_[0].value.as < epoxy::Variable > ()}; }
    break;

  case 28: // ArgumentList: ArgumentList "," Variable
                                    { yylhs.value.as < std::vector<epoxy::Variable> > () = yystack_[2].value.as < std::vector<epoxy::Variable> > (); yylhs.value.as < std::vector<epoxy::Variable> > ().push_back(yystack_[0].value.as < epoxy::Variable > ()); }
    break;

  case 29: // Struct: "struct" "<identifier>" "{" VariableList "}"
                                                           { yylhs.value.as < epoxy::Struct > () = epoxy::Struct{yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<epoxy::Variable> > ()}; }
    break;

  case 30: // Struct: "struct" "<identifier>" "{" "}"
                                                           { yylhs.value.as < epoxy::Struct > () = epoxy::Struct{yystack_[2].value.as < std::string > (), {}}; }
    break;

  case 31: // Variable: Primitive "<identifier>"
                                 { yylhs.value.as < epoxy::Variable > () = epoxy::Variable{yystack_[1].value.as < epoxy::Primitive > (), yystack_[0].value.as < std::string > (), false}; }
    break;

  case 32: // Variable: Primitive "*" "<identifier>"
                                 { yylhs.value.as < epoxy::Variable > () = epoxy::Variable{yystack_[2].value.as < epoxy::Primitive > (), yystack_[0].value.as < std::string > (), true};  }
    break;

  case 33: // Variable: "<identifier>" "<identifier>"
                                 { yylhs.value.as < epoxy::Variable > () = epoxy::Variable{yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > (), false}; }
    break;

  case 34: // Variable: "<identifier>" "*" "<identifier>"
                                 { yylhs.value.as < epoxy::Variable > () = epoxy::Variable{yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), true};  }
    break;

  case 35: // VariableList: Variable ";"
                                     { yylhs.value.as < std::vector<epoxy::Variable> > () = {yystack_[1].value.as < epoxy::Variable > ()}; }
    break;

  case 36: // VariableList: VariableList Variable ";"
                                     { yylhs.value.as < std::vector<epoxy::Variable> > () = yystack_[2].value.as < std::vector<epoxy::Variable> > (); yylhs.value.as < std::vector<epoxy::Variable> > ().push_back(yystack_[1].value.as < epoxy::Variable > ()); }
    break;

  case 37: // Primitive: "void"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kVoid; }
    break;

  case 38: // Primitive: "int8_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kInt8; }
    break;

  case 39: // Primitive: "int16_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kInt16; }
    break;

  case 40: // Primitive: "int32_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kInt32; }
    break;

  case 41: // Primitive: "int64_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kInt64; }
    break;

  case 42: // Primitive: "uint8_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kUnsignedInt8; }
    break;

  case 43: // Primitive: "uint16_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kUnsignedInt16; }
    break;

  case 44: // Primitive: "uint32_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kUnsignedInt32; }
    break;

  case 45: // Primitive: "uint64_t"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kUnsignedInt64; }
    break;

  case 46: // Primitive: "double"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kDouble; }
    break;

  case 47: // Primitive: "float"
               { yylhs.value.as < epoxy::Primitive > () = epoxy::Primitive::kFloat; }
    break;



            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -25;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       1,     4,    89,     1,   -25,    39,   -25,   -25,    74,    62,
      63,    64,   -25,    77,   -25,   -25,   -25,   -25,    83,    82,
      85,   -25,   -25,   -10,    22,    -9,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,    35,    87,
       6,    49,    71,    73,   -25,   -25,    84,    -8,    72,   -25,
     -25,   -25,    90,    75,   -25,    36,    76,    50,   -25,   -25,
      91,   -25,   -25,   -25,   -25,    79,   -25,    36,   -25,   -25,
     -25,    80,   -25
  };

  const signed char
  Parser::yydefact_[] =
  {
       3,     0,     0,     2,     4,     0,     1,     5,     0,     0,
       0,     0,     7,     0,     8,    12,    10,    11,     0,     0,
       0,     6,     9,     0,     0,     0,    30,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,     0,
       0,     0,    24,     0,    27,    13,    16,     0,     0,    33,
      35,    29,     0,     0,    31,     0,    21,     0,    15,    14,
      18,    34,    36,    32,    26,    22,    25,     0,    28,    17,
      23,    19,    20
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -25,   -25,   -25,    98,   -25,    95,   -25,   -25,   -25,    37,
     -25,   -25,   -24,   -25,   -19
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     2,     3,     4,    13,    14,    15,    47,    16,    65,
      43,    17,    39,    40,    41
  };

  const signed char
  Parser::yytable_[] =
  {
      44,    26,    45,    59,     1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    52,    51,    38,    46,
      60,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     5,    68,    38,    42,    66,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    66,     8,
      38,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    48,    49,    64,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    53,    54,    38,     9,
      10,    11,     9,    10,    11,    12,    56,    57,    21,     6,
      18,    19,    20,    23,    24,    25,    50,    55,    58,    62,
      61,     7,    67,    63,    71,    69,    70,    72,    22
  };

  const signed char
  Parser::yycheck_[] =
  {
      24,    11,    11,    11,     3,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    40,    11,    28,    28,
      28,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    28,    57,    28,    13,    55,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    67,    10,
      28,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    27,    28,    28,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    27,    28,    28,     5,
       6,     7,     5,     6,     7,    11,    13,    14,    11,     0,
      28,    28,    28,    10,    12,    10,     9,    26,    14,     9,
      28,     3,    26,    28,    67,    14,    27,    27,    13
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,    30,    31,    32,    28,     0,    32,    10,     5,
       6,     7,    11,    33,    34,    35,    37,    40,    28,    28,
      28,    11,    34,    10,    12,    10,    11,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    28,    41,
      42,    43,    13,    39,    41,    11,    28,    36,    27,    28,
       9,    11,    41,    27,    28,    26,    13,    14,    14,    11,
      28,    28,     9,    28,    28,    38,    43,    26,    41,    14,
      27,    38,    27
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    29,    30,    30,    31,    31,    32,    32,    33,    33,
      34,    34,    34,    35,    35,    36,    36,    36,    36,    37,
      37,    37,    37,    37,    37,    38,    38,    39,    39,    40,
      40,    41,    41,    41,    41,    42,    42,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     5,     4,     1,     2,
       1,     1,     1,     4,     5,     2,     1,     3,     2,     7,
       8,     5,     6,     7,     4,     1,     1,     1,     3,     5,
       4,     2,     3,     2,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };


#if EPOXY_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"<end of contents>\"", "error", "\"invalid token\"", "\"namespace\"",
  "\"class\"", "\"struct\"", "\"function\"", "\"enum\"",
  "\"<invalid token>\"", "\";\"", "\"{\"", "\"}\"", "\"(\"", "\")\"",
  "\",\"", "\"void\"", "\"int8_t\"", "\"int16_t\"", "\"int32_t\"",
  "\"int64_t\"", "\"uint8_t\"", "\"uint16_t\"", "\"uint32_t\"",
  "\"uint64_t\"", "\"double\"", "\"float\"", "\"->\"", "\"*\"",
  "\"<identifier>\"", "$accept", "SourceFile", "NamespaceList",
  "Namespace", "NamespaceItems", "NamespaceItem", "Enum", "IdentifierList",
  "Function", "PrimitiveOrIdentifier", "ArgumentList", "Struct",
  "Variable", "VariableList", "Primitive", YY_NULLPTR
  };
#endif


#if EPOXY_DEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    99,    99,   100,   104,   105,   109,   110,   114,   115,
     119,   120,   121,   125,   126,   130,   131,   132,   133,   137,
     138,   139,   140,   141,   142,   146,   147,   151,   152,   156,
     157,   161,   162,   163,   164,   168,   169,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // EPOXY_DEBUG


} // epoxy



void epoxy::Parser::error(const epoxy::Parser::location_type& loc,
                          const std::string& message) {
  driver.ReportParsingError(loc, message);
}
