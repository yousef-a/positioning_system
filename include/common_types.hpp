#pragma once
#include <stdint.h>

const struct tPacketProp{
	uint8_t pad_len = 3;
	uint8_t hdr_len = 2;
	uint8_t crc_len = 2;
	uint8_t pad_data[3] = { 0xFF, 0x00, 0xAA };
	uint8_t pad_EOH = 0xFF;
	uint8_t pad_EOP = 0xFF;
}PacketProp;
enum class msg_type {optitrack, position, attitude, switcher, payload, nozzle, obstacle, mission,ack,internal_msg_start,internal_ros };
enum class msg_type_optitrack {position, attitude};
enum class block_type {controller, provider, reference};
enum class switcher_msg_type {controller, provider, reference};
enum class ack_msg_type { raw_packet, payload, nozzle, obstacle, mission,ack,internal_msg_start,internal_ros };
enum class ros_msg_type {ros_obstacle_distance,ros_aircraft_attitude};
