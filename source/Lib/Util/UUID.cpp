#include "UUID.h"

lib::util::UUID::UUID() {
	uuid_generate_random(this->t_uuid);
}

lib::util::UUID::~UUID() {}

const uuid_t &lib::util::UUID::get(void) const {
    return this->t_uuid;
}

lib::util::String lib::util::UUID::string(void) {
	char ch_uuid[37];
	uuid_unparse(this->t_uuid, ch_uuid);
	return lib::util::String(ch_uuid);
}

void lib::util::UUID::trace(void) {
	char uuid_str[37];
	uuid_unparse(this->t_uuid, uuid_str);
	std::cout << "UUIDv4: " << uuid_str << std::endl;
}

lib::util::UUID &lib::util::UUID::operator=(const UUID &o_uuid) {
	if (this != &o_uuid)
		std::memcpy(this->t_uuid, o_uuid.t_uuid, sizeof(uuid_t));
	return *this;
}


