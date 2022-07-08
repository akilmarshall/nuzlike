import React from 'react'
import { useSelector } from 'react-redux'
import { staticSpriteURL } from './PkmnInfo'
import { Card, Grid } from '@nextui-org/react'

function Party() {
    const party = useSelector(state => state.player.party)

    function renderPkmn(id) {
        return (
        <Grid>
            <Card isHoverable variant="bordered" css={{ mw: "120px" }} >
                <Card.Body>
                    <img src={staticSpriteURL(id)} alt=""/>
                </Card.Body>
            </Card>
        </Grid>
        )
    }

    return (
    <>
        <center>
        <h2>Pokemon Party</h2>
        </center>
        <Grid.Container justify='center' direction='row' gap={2}>
            {party.map(renderPkmn)}
        </Grid.Container>
    </>
    )
}
export default Party
