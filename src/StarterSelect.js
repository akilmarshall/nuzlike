import React, { useDisclosure, useState } from 'react'
import { useSelector, useDispatch } from 'react-redux'
import { staticSpriteURL } from './PkmnInfo'
import { Card, Button, Grid } from '@nextui-org/react'
import { addToParty } from './slice/Player'
import Party from './Party'

function StarterSelect() {
    const starters = useSelector(state => state.player.starterPokemon)
    const [confirm_, setConfirm] = useState(false)
    const [starter, setStarter] = useState(0)
    const dispatch = useDispatch()

    function renderPokemon(id) {
        // TODO add pokemon information to the card
        return (
        <Grid xs={2}>
            <Card isHoverable variant="bordered" css={{ mw: "120px" }} >
                <Card.Body onClick={() => {setConfirm(!confirm_);setStarter(id)}}>
                    <img src={staticSpriteURL(id)} alt="" />
                </Card.Body>
            </Card>
        </Grid>
        )
    }

    function choice() {
        return (
        <>
            <h2>Choose Your Starter</h2>
            <Grid.Container>
                    {starters.map(renderPokemon)}
            </Grid.Container>
        </>
        )
    }
    function confirmChoice(id) {
        // TODO need an onClick method to navigate somewhere else
        return (
        <>
            <center>
                <h3>Are you sure?</h3>
                <Card variant="" css={{ mw: "120px" }} >
                    <Card.Body onClick={() => confirmChoice(id)}>
                        <img src={staticSpriteURL(id)} alt="" />
                    </Card.Body>
                </Card>
            </center>
            <center>
                <Grid.Container gap={2}>
                    <Grid>
                        <Button flat color="secondary" auto onPress={() => {setConfirm(!confirm_);setStarter(0)}}>no</Button>
                    </Grid>
                    <Grid>
                        <Button flat color="primary" auto onPress={() => {dispatch(addToParty(starter));setConfirm(!confirm_)}}>yes</Button>
                    </Grid>
                </Grid.Container>
            </center>
        </>
        )
    }
    return (
    <>
        {!confirm_ && choice()}
        {confirm_ && confirmChoice(starter)}
        <Party />
    </>
    )
}
export default StarterSelect
