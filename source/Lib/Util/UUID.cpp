#include "UUID.h"

Lib::Util::UUID::UUID() {
	uuid_generate_random(this->t_uuid);
}

Lib::Util::UUID::~UUID() {}

const uuid_t &Lib::Util::UUID::get(void) const {
    return this->t_uuid;
}

Lib::Util::String Lib::Util::UUID::string(void) {
	char ch_uuid[37];
	uuid_unparse(this->t_uuid, ch_uuid);
	return Lib::Util::String(ch_uuid);
}

void Lib::Util::UUID::trace(void) {
	char uuid_str[37];
	uuid_unparse(this->t_uuid, uuid_str);
	std::cout << "UUIDv4: " << uuid_str << std::endl;
}

Lib::Util::UUID &Lib::Util::UUID::operator=(const UUID &o_uuid) {
	if (this != &o_uuid)
		std::memcpy(this->t_uuid, o_uuid.t_uuid, sizeof(uuid_t));
	return *this;
}


