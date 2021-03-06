//  Copyright (c) 2001-2011 Joel de Guzman
//  Copyright (c) 2001-2017 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(PHYLANX_AST_PARSER_EXPRESSION_HPP)
#define PHYLANX_AST_PARSER_EXPRESSION_HPP

///////////////////////////////////////////////////////////////////////////////
// Spirit v2.5 allows you to suppress automatic generation
// of predefined terminals to speed up complation. With
// BOOST_SPIRIT_NO_PREDEFINED_TERMINALS defined, you are
// responsible in creating instances of the terminals that
// you need (e.g. see qi::uint_type uint_ below).
#define BOOST_SPIRIT_NO_PREDEFINED_TERMINALS

// Uncomment this if you want to enable debugging
// #define BOOST_SPIRIT_QI_DEBUG

#include <phylanx/config.hpp>
#include <phylanx/ast/parser/ast.hpp>
#include <phylanx/ast/parser/error_handler.hpp>
#include <phylanx/ast/parser/skipper.hpp>

#include <boost/spirit/include/qi.hpp>

namespace phylanx { namespace ast { namespace parser
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    ///////////////////////////////////////////////////////////////////////////
    //  The expression grammar
    template <typename Iterator>
    struct expression_base
    {
        expression_base(error_handler<Iterator>& error_handler);

        qi::rule<Iterator, ast::expression(), skipper<Iterator>> expr;

        qi::rule<Iterator, ast::operand(), skipper<Iterator>> unary_expr;
        qi::rule<Iterator, ast::operand(), skipper<Iterator>> primary_expr;

        qi::rule<Iterator, ast::function_call(), skipper<Iterator>>
            function_call;

        qi::rule<Iterator, std::list<ast::expression>(), skipper<Iterator>>
            argument_list;

        qi::rule<Iterator, std::string(), skipper<Iterator>> identifier;

        qi::symbols<char, ast::optoken> unary_op;
        qi::symbols<char, ast::optoken> binary_op;
        qi::symbols<char> keywords;
    };

    template <typename Iterator>
    struct expression
      : expression_base<Iterator>,
        qi::grammar<Iterator, ast::expression(), skipper<Iterator>>
    {
        expression(error_handler<Iterator>& error_handler);
    };
}}}

#endif
