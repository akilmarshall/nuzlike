import React from 'react'
import { useSelector } from 'react-redux'
import { HStack, Image, Center, Heading } from '@chakra-ui/react'
import { staticSpriteURL } from './Sprites'

function Party() {
    const party = useSelector(state => state.player.party)
    console.log(party)

    function renderPkmn(id) {
        return (
            <Image src={staticSpriteURL(id)} />
        )
    }

    return (
    <>
        <Center>
        <Heading as='h2' size='lg'>Pokemon Party</Heading>
        </Center>
        <Center>
            <HStack>
                {party.map(renderPkmn)}
            </HStack>
        </Center>
    </>
    )
}
export default Party
