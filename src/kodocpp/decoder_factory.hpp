// Copyright Steinwurf ApS 2011-2013.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <cstdint>

#include "api_config.hpp"
#include "code_type.hpp"
#include "finite_field.hpp"
#include "decoder.hpp"

namespace kodocpp
{
    class decoder_factory_interface;

    class KODOCPP_API decoder_factory
    {
    public:

        decoder_factory(code_type code,
                        finite_field field,
                        uint32_t max_symbols,
                        uint32_t max_symbol_size,
                        bool trace_enabled = false);

        ~decoder_factory();

        decoder build();

        void set_symbols(uint32_t symbols);

        void set_symbol_size(uint32_t symbol_size);

        uint32_t max_symbols() const;

        uint32_t max_symbol_size() const;

        uint32_t max_block_size() const;

        uint32_t max_payload_size() const;

    private:

        decoder_factory_interface* m_factory_wrapper;
    };
}
