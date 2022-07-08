import React, { useState } from 'react'
import { useSelector, useDispatch } from 'react-redux'
import { staticSpriteURL } from './PkmnInfo'
import { Card, Button, Grid } from '@nextui-org/react'
import { addToParty } from './slice/Player'
import { Link } from 'react-router-dom'

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
            <center>
                <h2>Choose Your Starter</h2>
            </center>
            <Grid.Container alignItems='center' direction='column' gap={2}>
                    {starters.map(renderPokemon)}
            </Grid.Container>
        </>
        )
    }
    function confirmChoice(id) {
        return (
        <>
            <center>
                <h3>Are you sure?</h3>
                <Card variant="" css={{ mw: "120px" }} >
                    <Card.Body onPress={() => confirmChoice(id)}>
                        <img src={staticSpriteURL(id)} alt="" />
                    </Card.Body>
                </Card>
            </center>
            <Grid.Container justify='center' direction='row' gap={2}>
                <Grid>
                    <Button flat color="secondary" auto onPress={() => {setConfirm(!confirm_);setStarter(0)}}>No</Button>
                </Grid>
                <Grid>
                    <Button flat color="primary" auto onPress={() => dispatch(addToParty(starter))}>
                        <Link to="/party" as={Button}>Yes</Link>
                    </Button>
                </Grid>
            </Grid.Container>
        </>
        )
    }
    return (
    <>
        {!confirm_ && choice()}
        {confirm_ && confirmChoice(starter)}
    </>
    )
}
export default StarterSelect
