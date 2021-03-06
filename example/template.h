#include <iostream>
#include <string>

namespace macros {
	template<typename O, typename T0>
	void fact(O &o, T0 vsym_n);

	template<typename O, typename T0, typename T1, typename T2>
	void input(O &o, T0 vsym_name, T1 vsym_value, T2 vsym_type);

	template<typename O, typename T0, typename T1>
	void print_users(O &o, T0 vsym_users, T1 vsym_active);

	template<typename O, typename T0>
	void fact(O &o, T0 vsym_n) {
		o << u8R"content"""(
    )content"""";
		if ((vsym_n == 1)) {
			o << u8R"content"""(
        <span>)content"""";
			o << vsym_n;
			o << u8R"content"""(</span>
    )content"""";
		} else {
			o << u8R"content"""(
        <span>)content"""";
			o << vsym_n;
			o << u8R"content"""( ⋅ )content"""";
			macros::fact(o, (vsym_n - 1));
			o << u8R"content"""(</span>
    )content"""";
		}
		o << u8R"content"""(
)content"""";
	}

	template<typename O, typename T0, typename T1, typename T2>
	void input(O &o, T0 vsym_name, T1 vsym_value, T2 vsym_type) {
		o << u8R"content"""(
    <input type=")content"""";
		o << vsym_type;
		o << u8R"content"""(" name=")content"""";
		o << vsym_name;
		o << u8R"content"""(" value=")content"""";
		o << vsym_value;
		o << u8R"content"""(">
)content"""";
	}

	template<typename O, typename T0, typename T1>
	void print_users(O &o, T0 vsym_users, T1 vsym_active) {
		o << u8R"content"""(
    <ol>

    )content"""";
		{
			auto vsym_label = std::string("Deactivate");
			o << u8R"content"""(
    )content"""";
			if (!(vsym_active)) {
				o << u8R"content"""(
        )content"""";
				{
					vsym_label = std::string("Activate");
					o << u8R"content"""(
    )content"""";
				}
			} else {
			}
			o << u8R"content"""(

    )content"""";
			for (const auto& vsym_user : vsym_users) {
				if (((vsym_user.active) == vsym_active)) {
					o << u8R"content"""(
        <li>
            <span>)content"""";
					o << (vsym_user.firstname);
					o << u8R"content"""( )content"""";
					o << (vsym_user.lastname);
					o << u8R"content"""(</span>
            <button type="submit" value=")content"""";
					o << (vsym_user.id);
					o << u8R"content"""(" name=")content"""";
					o << vsym_label;
					o << u8R"content"""("> )content"""";
					o << vsym_label;
					o << u8R"content"""( </button>
        </li>
    )content"""";
				}
			}
			o << u8R"content"""(

    </ol>
)content"""";
		}
	}
}

template<typename O, typename T0, typename T1>
void render_template(O &o, T0 vsym_history, T1 vsym_users) {
	o << u8R"content"""(<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Example</title>
<style type="text/css">
    ol {
        list-style-type: none;
    }

    li {
        margin: 10px 0;
    }

    button {
        margin: 3px 0;
    }

    p {
        margin: 2px 0;
    }
</style>
</head>

<body>

)content"""";
	o << u8R"content"""(

)content"""";
	o << u8R"content"""(


)content"""";
	o << u8R"content"""(

<h3>Example</h3>
<form action="">
    )content"""";
	macros::input(o, std::string("a"), std::string(""), std::string("text"));
	o << u8R"content"""(
    )content"""";
	macros::input(o, std::string("b"), std::string(""), std::string("text"));
	o << u8R"content"""(
    )content"""";
	macros::input(o, std::string("c"), std::string("Ok"), std::string("submit"));
	o << u8R"content"""(
</form>

<ol>
    )content"""";
	for (const auto& vsym_entry : vsym_history) {
		if (true) {
			o << u8R"content"""(
        )content"""";
			{
				auto vsym_a = (vsym_entry.first);
				o << u8R"content"""(
        )content"""";
				{
					auto vsym_b = (vsym_entry.second);
					o << u8R"content"""(

        <li>
            <p>)content"""";
					o << vsym_a;
					o << u8R"content"""( ⋅ )content"""";
					o << vsym_b;
					o << u8R"content"""( = )content"""";
					o << (vsym_a * vsym_b);
					o << u8R"content"""(</p>
            <p>)content"""";
					o << vsym_a;
					o << u8R"content"""(² + )content"""";
					o << vsym_b;
					o << u8R"content"""(² = )content"""";
					o << ((vsym_a * vsym_a) + (vsym_b * vsym_b));
					o << u8R"content"""(</p>
            <p>)content"""";
					macros::fact(o, vsym_a);
					o << u8R"content"""(</p>
        </li>

    )content"""";
				}
			}
		}
	}
	o << u8R"content"""(
</ol>

<form action="">
    <h3>Active Users</h3>
    )content"""";
	macros::print_users(o, vsym_users, true);
	o << u8R"content"""(

    <h3>Inactive Users</h3>
    )content"""";
	macros::print_users(o, vsym_users, false);
	o << u8R"content"""(
</form>

</body>
</html>

)content"""";
}

